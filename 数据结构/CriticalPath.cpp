#include"GraphAdjList.h"
using namespace std;

int main(){
    GraphAdjList<int,int> g(6);
    for(int i=0;i<6;i++) g.SetVex(i,i);   // 顶点数据就用编号，方便对结果

    g.AddArc(0,1,3);   // V1->V2
    g.AddArc(0,2,2);   // V1->V3
    g.AddArc(1,3,2);   // V2->V4
    g.AddArc(1,4,3);   // V2->V5
    g.AddArc(2,3,4);   // V3->V4
    g.AddArc(3,5,2);   // V4->V6
    g.AddArc(4,5,3);   // V5->V6

    cout<<"工期："<<g.CriticalPath()<<endl;

    system("pause");
    return 0;
}