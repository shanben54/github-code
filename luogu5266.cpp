//学籍管理系统，可以储存每个学生的名字和分数，我感觉像python里面的字典
//使用了stl里面的map，可以储存两种类型的数据，第一个为下标，第二个为储存的数据
#include<bits/stdc++.h>
using namespace std;
int n,opt,num,ans;
string name;
map<string,int>ds;
int main(){
    cin>>n;
    while(n--){
        cin>>opt;
        if(opt==1){//插入和修改
            cin>>name>>num;
            ds[name]=num;//不需要插入数据，如果你访问的ds[name]不存在，则会自动创建一个ds[name]，里面的数据为默认值
            cout<<"OK"<<endl;
        }else if(opt==2){//查询
            cin>>name;
            if(ds.find(name)!=ds.end()){//和set一样，如果数据不存在，find会返回end()
                cout<<ds[name]<<endl;
            }
            else{
                cout<<"Not found"<<endl;
            }
        }else if(opt==3){//删除
            cin>>name;
            if(ds.find(name)!=ds.end()){
                ds.erase(ds.find(name));
                cout<<"Deleted successfully"<<endl;
            }else{
                cout<<"Not found"<<endl;
            }
        }else{//汇总
            cout<<ds.size()<<endl;
        }
    }
    return 0;
}