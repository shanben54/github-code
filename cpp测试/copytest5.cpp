#include <iostream>
#include "bitree.h"

int main(){
    BiTree<char> a;
    a.Create("AB#D##C##");
    {
        BiTree<char> b = a;
        std::cout << "b: "; b.PreOrder(); std::cout << std::endl;
    }                                    // b 在这里析构

    std::cout << "b 死了,a: "; a.PreOrder(); std::cout << std::endl;

    BiTree<char> c;
    c = a;
    std::cout << "c: "; c.PreOrder(); std::cout << std::endl;

    const BiTree<char>& ref = a;         // 顺便验证从 const 树拷贝
    BiTree<char> d = ref;
    std::cout << "d: "; d.PreOrder(); std::cout << std::endl;

    std::cout << "正常结束" << std::endl;
    return 0;
  }
