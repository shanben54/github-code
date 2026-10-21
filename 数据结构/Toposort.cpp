#include"GraphAdjList.h"
using namespace std;

int main(){
    GraphAdjList<int,int> g(4);
    for(int i=0;i<4;i++){
        g.SetVex(i,i);
    }
    g.AddArc(0,1,0); 
    g.AddArc(0,2,0); 
    g.AddArc(1,3,0); 
    g.AddArc(2,3,0);
    int order[4];
    cout<<g.Toposort(order)<<endl;   // 期望输出 4 个顶点，返回 1
    g.AddArc(3,0,0);            // 加一条成环的弧
    cout<<g.Toposort(order)<<endl;   // 期望输出少于 4 个顶点，返回 0
    system("pause");
    return 0;
}