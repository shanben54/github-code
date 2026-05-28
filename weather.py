import requests
import json
import sys
##获取天气的信息
def get_weather(city):
    try:
        url = f"https://wttr.in/{city}?format=j1&lang=zh"##构造向网站发送请求来获取天气数据的url
        headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36'##请求头，伪装成浏览器而不是程序，来避免被拒绝请求
        }
        response = requests.get(url, headers=headers, timeout=10)##拼装后发送请求
        response.raise_for_status()##如果返回的状态码不是200就返回错误
        data = response.json()##将json的数据转换为python的字典
        return data
    ##如果请求失败就显示错误
    except requests.exceptions.RequestException as e:
        print(f"❌ 请求失败: {e}")
        return None
##将天气的数据打印出来
def display_weather(data, city):
    if not data:
        return
    try:
        current = data['current_condition'][0]
        weather_desc = current['weatherDesc'][0]['value']
        temp_c = current['temp_C']
        feels_like_c = current['FeelsLikeC']
        humidity = current['humidity']
        wind_speed = current['windspeedKmph']
        wind_dir = current['winddir16Point']
        today = data['weather'][0]
        max_temp = today['maxtempC']
        min_temp = today['mintempC']
        print("\n" + "=" * 50)
        print(f"🌍 城市: {city}")
        print("=" * 50)
        print(f"\n🌤️  当前天气: {weather_desc}")
        print(f"🌡️  温度: {temp_c}°C (体感 {feels_like_c}°C)")
        print(f"💧 湿度: {humidity}%")
        print(f"💨 风速: {wind_speed} km/h ({wind_dir})")
        print(f"📊 今日温度范围: {min_temp}°C ~ {max_temp}°C")
        print("\n📅 未来3天预报:")
        print("-" * 50)
        for i, day in enumerate(data['weather'][:3]):##未来三天的天气情况
            date = day['date']
            max_t = day['maxtempC']
            min_t = day['mintempC']
            desc = day['hourly'][4]['weatherDesc'][0]['value']
            
            print(f"  📆 {date}: {min_t}°C ~ {max_t}°C | {desc}")
        
        print("\n" + "=" * 50 + "\n")
        
    except (KeyError, IndexError) as e:
        print(f"❌ 解析数据失败: {e}")
##主函数
def main():
    print("🌤️  Python 天气查询工具")
    print("=" * 30)
    ##提示用户输入
    while True:
        print("\n请选择操作:")
        print("1. 查询天气")
        print("2. 常用城市快速查询")
        print("3. 退出")
        choice = input("\n请输入选项 (1/2/3): ").strip()
        if choice == "1":
            city = input("请输入城市名称（中文或英文）: ").strip()
            if city:
                print(f"\n⏳ 正在查询 {city} 的天气...")
                data = get_weather(city)
                display_weather(data, city)
            else:
                print("❌ 请输入有效的城市名称！")  
        elif choice == "2":
            cities = {
                "1": ("北京", "Beijing"),
                "2": ("上海", "Shanghai"),
                "3": ("广州", "Guangzhou"),
                "4": ("深圳", "Shenzhen"),
                "5": ("成都", "Chengdu"),
                "6": ("杭州", "Hangzhou")
            }
            print("\n常用城市:")
            for key, (cn, en) in cities.items():
                print(f"  {key}. {cn} ({en})")
            city_choice = input("请选择城市编号: ").strip()
            if city_choice in cities:
                cn_name, en_name = cities[city_choice]
                print(f"\n⏳ 正在查询 {cn_name} 的天气...")
                data = get_weather(en_name)
                display_weather(data, cn_name)
            else:
                print("❌ 无效的选择！")     
        elif choice == "3":
            print("👋 再见！")
            break##退出函数
        else:
            print("❌ 无效的选项，请重新输入！")
if __name__ == "__main__":##程序主函数
    try:
        main()
    except KeyboardInterrupt:
        print("\n\n👋 程序已退出！")
        sys.exit(0)##退出程序