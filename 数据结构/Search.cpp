#include<iostream>
#include<vector>
using namespace std;

//简单二分查找，直接判断中值是否为要找的，如果不是再折半去查找
//闭区间，所以终止条件是low<=high，按区间来查找，没找到就返回-1
int BinarySearch1(const vector<int> &a,int key){
    int low=0;
    int high=(int)a.size()-1;
    while(low<=high){
        int mid=high-(high-low)/2;
        if(a[mid]==key){
            return mid;
        }else if(a[mid]<key){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}

//完全版二分查找
//low表示low左边都是不满足条件的，high表示high及右边都是满足条件的
//不是直接查找值，而是通过不断缩减区间，最终只剩一个元素，就是最早满足条件的元素
int BinarySearch(const vector<int> &a,int key){
    int low=0;
    int high=(int)a.size();
    while(low<high){
        int mid=low+(high-low)/2;//high开，所以mid要用下取值
        if(a[mid]>=key){//二分条件，high表示满足条件的候选，不一定是最终答案
            high=mid;
        }else{
            low=mid+1;
        }
    }
    return low;//最终得到的是第一个大于等于key值的元素下标，哪怕不是key，也可以表示在这个地方插入key值不会影响顺序
}

int main(){
    vector<int> a;
    for(int i=0;i<7;i++){
        a.push_back(i);
    }
    cout<<"查找0 预期:0 实际："<<BinarySearch1(a,0)<<endl;
    cout<<"查找1 预期:1 实际: "<<BinarySearch1(a,1)<<endl;
    cout<<"查找2 预期:2 实际: "<<BinarySearch1(a,2)<<endl;
    cout<<"查找3 预期:3 实际: "<<BinarySearch1(a,3)<<endl;
    cout<<"查找4 预期:4 实际: "<<BinarySearch1(a,4)<<endl;
    cout<<"查找5 预期:5 实际: "<<BinarySearch1(a,5)<<endl;
    cout<<"查找6 预期:6 实际: "<<BinarySearch1(a,6)<<endl;
    cout<<"查找7 预期:-1 实际: "<<BinarySearch1(a,7)<<endl;
    system("pause");
    return 0;
}