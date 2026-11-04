#include <iostream>
#include <stdexcept>
#include "linklist.h"

static bool g_boom = false;

struct Bomb{
    int v;
    Bomb(int x = 0) : v(x) {}
    Bomb(const Bomb& o) : v(o.v){
        if(g_boom) throw std::runtime_error("复制时炸了");
    }
  };

int main(){
    LinkList<Bomb> a, b;
    a.LinkListInsert(1, Bomb(10));
    a.LinkListInsert(2, Bomb(20));
    a.LinkListInsert(3, Bomb(30));
    b.LinkListInsert(1, Bomb(1));
    b.LinkListInsert(2, Bomb(2));

    g_boom = true;                 // 从这里开始，每次复制都炸
    try {
        a = b;
    } catch(const std::exception& e){
        std::cout << "捕获到：" << e.what() << std::endl;
    }
    g_boom = false;
    std::cout << "赋值失败后 a 的长度 = " << a.GetLength() << std::endl;
    return 0;
  }