#include"GraphAdjList.h"
using namespace std;

int main(){
    GraphAdjList<int,int> g(6);
    g.SetVex(0,1);
    g.SetVex(1,2);
    g.SetVex(2,3);
    g.SetVex(3,4);
    g.SetVex(4,5);
    g.SetVex(5,6);
    g.AddEdge(0,1,3);
    g.AddEdge(0,2,1);
    g.AddEdge(2,4,8);
    g.AddEdge(3,5,2);
    g.AddEdge(2,3,5);
    g.AddEdge(1,3,2);
    int lowcost[6];
    int adjcex[6];
    g.Prim(lowcost,adjcex);
    system("pause");
    return 0;
}