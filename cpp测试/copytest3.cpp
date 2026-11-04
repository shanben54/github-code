#include <iostream>
#include "linklist.h"
using namespace std;

int main(){
    LinkList<int> a;
    a.TailInsert(3);
    int e;

    LinkList<int> b = a;                 // 1. 拷贝构造
    b.LinkListDelete(1, e);
    cout << "拷贝构造后自删:a=" << a.GetLength() << " b=" << b.GetLength() << endl;

    LinkList<int> c;
    c = a;                               // 2. 拷贝赋值
    c.LinkListDelete(1, e);
    cout << "拷贝赋值后自删:a=" << a.GetLength() << " c=" << c.GetLength() << endl;

    a = a;                               // 3. 自赋值
    cout << "自赋值后:a=" << a.GetLength() << endl;

    LinkList<int> empty_;
    a = empty_;                          // 4. 从空表赋值
    cout << "赋空后:a=" << a.GetLength() << endl;

    cout << "正常结束" << endl;
    return 0;
  }