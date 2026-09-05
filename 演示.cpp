#include<iostream>>
#include<set>
#include<map>
#include<string>
using namespace std;

int main(){

    set<int> ds;//集合

    ds.insert(10);//添加元素
    ds.insert(20);
    ds.insert(30);
    ds.insert(20);//添加重复元素不会存入

    set<int>::iterator it;//迭代器，储存元素的地址
    ds.erase(20);//删除元素，如果不存在就不会有操作
    ds.erase(it);//删除这个地址对应的元素
    ds.end();//返回最后一个元素的下一个元素的地址
    it=ds.find(30);//查询，返回地址，如果不存在，返回ds.end()
    it=ds.lower_bound(15);//查询不小于这个元素的最小数，返回20的地址
    it=ds.upper_bound(15);//返回大于这个元素的最小数的地址，返回20

    ds.empty();//如果为空的话返回1，如果不为空就返回0
    ds.size();//返回集合中的元素的个数


    map<string,string> mp;//映射表，红黑树，第一个是下标，第二个是值

    mp["apple"]="苹果";//查询下标，不存在，自动创建，0，string
    mp["banana"]="香蕉";//添加元素
    cout<<mp["orange"];//
    mp["orange"]="橙子";
    cout<<mp["orange"];

    cout<<mp["banana"];//打印这个下标所对应的值
    mp.erase("orange");//删除，下标所对应的元素

    map<string,string>::iterator mit;//迭代器，储存地址
    ds.end();//返回最后一个元素的下一个元素的地址
    mit=mp.find("apple");//查询并返回这个下标所对应的元素的地址，如果返回mp.end()

    mp.empty();//如果为空就返回1，如果不为空就返回0
    mp.size();//查询映射表的元素个数


    return 0;
}