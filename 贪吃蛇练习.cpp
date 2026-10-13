//贪吃蛇小游戏，个人练习用
/*整体框架
  1.读入操作
  2.画一帧
  3.判断下一步是否合法，打印蛇
*/
//每帧都打印出来，才能让蛇动起来
//新的知识点，控制台操作，非阻塞读键，ANSI转义，帧循环
#include <iostream>
#include <deque>        // 蛇身待会儿要用的队列
#include <conio.h>      // _kbhit / _getch：不用敲回车的按键读取
#include <windows.h>    // 开 ANSI 支持、Sleep
#include<cstdlib>
#include<time.h>

// 老版本头文件可能没定义这个常量，没有就自己补一个（值就是 0x0004）
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

// ---- 画面尺寸 ----
const int W = 30;       // 宽（列数）
const int H = 20;       // 高（行数）

// 让 Windows 控制台解析 ANSI 转义序列
// 不打开这一位的话，\033[... 会被当普通字符打印出来
void enableAnsi() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(h, &mode);
    SetConsoleMode(h, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

//生成一个合法的食物坐标
std::pair<int,int> Food(const std::deque<std::pair<int,int>> &snake){
    int fx,fy;
    bool onsnake;
    do{
        fx=2+rand()%(W-2);
        fy=2+rand()%(H-2);
        onsnake=false;
        for(auto c:snake){
            if(fx==c.first&&fy==c.second){
                onsnake=true;
                break;
            }
        }
    }
    while(onsnake);
    return {fx,fy};
}

// 把光标移到「第 x 列、第 y 行」（都是从 1 开始数）
// 转义格式是 \033[行;列H —— 注意先「行」后「列」，别写反
void gotoxy(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";
}

int main() {
    srand(time(0));
    system("chcp 65001 > nul");     // 让控制台用 UTF-8，中文提示才不会乱码
    enableAnsi();
    std::cout << "\033[?25l";//隐藏光标，防止光标闪烁
    std::cout << "\033[2J";         // 启动时清一次屏
    
    std::deque<std::pair<int,int>> snake={{W/2+1,H/2},{W/2,H/2},{W/2-1,H/2}};
    int dx=1,dy=0;//方向变量
    
    std::pair<int,int>food=Food(snake);

    bool running = true;
    while (running) {
        // ---- 1. 读输入：_kbhit() 没按键就立刻返回，不会把程序卡住 ----
        //      用 while 把缓冲区里的按键一次读空，连按才不会延迟
        while (_kbhit()) {
            int key = _getch();
            if      ((key == 'w' || key == 'W')&&dy!=1) dx=0,dy=-1;//不能往回走
            else if ((key == 's' || key == 'S')&&dy!=-1) dx=0,dy=1;
            else if ((key == 'a' || key == 'A')&&dx!=1) dx=-1,dy=0;
            else if ((key == 'd' || key == 'D')&&dx!=-1) dx=1,dy=0;
            else if (key == 'q' || key == 'Q') running = false;
        }

        // ---- 2. 画一帧：光标回左上角，整屏覆盖重画 ----
        //      别用 \033[2J 每帧清屏（会闪）；
        //      覆盖重画 + 每行末尾 \033[K 清残留，就不会闪
        gotoxy(1, 1);
        for (int y = 1; y <= H; ++y) {
            for (int x = 1; x <= W; ++x) {
                if (y == 1 || y == H || x == 1 || x == W)
                    std::cout << '#';               // 边框，撞墙判定以后用得到
                else
                    std::cout << ' ';
            }
            std::cout << "\033[K\n";                // 清掉本行行尾残留
        }
        
        //打印食物坐标
        gotoxy(food.first,food.second);
        std::cout<<'*';
        
        //下一个位置的坐标，先判断是否合法
        auto next=snake.front();
        next.first+=dx;
        next.second+=dy;
        
        //撞墙游戏结束
        if(next.first>W-1||next.first<2||next.second>H-1||next.second<2){
            gotoxy(1,H+6);
            std::cout << "\033[?25h";
            std::cout<<"GAMEOVER~\n";
            system("pause");
            return 0;
        }
        
        //吃到自己游戏结束
        for(auto c:snake){
            if(c==next){
                gotoxy(1,H+6);
                std::cout << "\033[?25h";
                std::cout<<"GAMEOVER~\n";
                system("pause");
                return 0;
            }
        }
        
        //吃到食物长度增加(不移动尾部)，同时生成新的食物坐标
        if(next==food){
            snake.push_front(next);
            food=Food(snake);
        }else{//啥都没有就正常移动
            snake.push_front(next);
            snake.pop_back();
        }
        
        //打印蛇
        for(size_t i=0;i<snake.size();i++){
            gotoxy(snake[i].first,snake[i].second);//使用位置来判断，这样更清晰
            if(i==0){
                std::cout<<'O';
            }else{
                std::cout<<'o';
            }
        }
        
        //底部打印游戏说明
        gotoxy(1, H + 2);
        std::cout << "WASD 移动    Q 退出\033[K\n";
        std::cout << std::flush;                    // 一帧一次性刷出去，减少闪烁

        // ---- 3. 控帧率：太快会闪，太慢手感迟钝 ----
        Sleep(80);
    }
    
    gotoxy(1, H + 6);
    std::cout << "\033[?25h";//显示光标
    std::cout << "Bye~\n";
    system("pause");        // 双击运行时留住窗口
    return 0;
}