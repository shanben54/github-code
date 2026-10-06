//顺序表的cpp写法
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

typedef string Elemtype;
const int MAXSIZE=100;

class SqList{
private:
  Elemtype data[MAXSIZE];//顺序表数组
  int length;//顺序表长度
public:
  //构造函数,初始化长度为0
  SqList():length(0){}
  
  //获取顺序表长度
  int GetLength()const{//函数后加const表示不修改对象的数据，这里只获取长度不用修改数据所以加const
    return length;
  }
  
  //获取第i个元素的值
  bool GetElem(int i,Elemtype &e)const{//要修改e的值，所以e前面加&引用
    if(i<1||i>length) return false;
    e=data[i-1];//注意下标
    return true;
  }
  
  //在第i个位置插入数据e
  bool ListInsert(int i,Elemtype e){
    if(length==MAXSIZE) return false;
    if(i<1||i>length+1) return false;
    
    //将i及之后的元素都向后移动一位，把第i个位置空出来，从后往前可以防止数据被覆盖
    //如果i=length+1，这个for循环不会进行
    for(int j=length-1;j>=i-1;j--){
        data[j+1]=data[j];
    }

    data[i-1]=e;
    length++;//更新长度
    return true;
  }
  
  //删除第i个位置的元素
  bool ListDelete(int i,Elemtype &e){
    if(length==0) return false;
    if(i<1||i>length) return false;
    
    //先将这个位置的数据赋值给e
    e=data[i-1];
    //将i+1及之后的位置都往前移动，把i的位置补上
    for(int j=i;j<length;j++){
        data[j-1]=data[j];
    }
    length--;//更新长度
    return true;
 }
};

int main() {
    SqList L;
    L.ListInsert(1,"2025年羽毛球");
    L.ListInsert(2,"世锦赛冠军是");
    L.ListInsert(3,"石宇奇！");
    cout<<L.GetLength()<<endl;
    string s;
    L.GetElem(3,s);
    cout<<s<<endl;
    system("pause");
    return 0;
  }