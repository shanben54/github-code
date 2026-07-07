//归并排序的例子
//首先将数组进行无序对半分割，直到不能分割为止，然后再对每个碎片拼合对原数组更新
//和快速排序一样都是用了分治的思想，但是快速排序重点是分，左右半区一边排序一边更新，归并排序重点是合，随意分割后再一一对比合并
#include<bits/stdc++.h>
using namespace std;
//将碎片合并的函数，左半边和右半边分别一一对比，因为左右半边已经是合并过的，分别都是有序的，然后一一对比，更新进原数组里
void merge(vector<int>& arr,int left,int right,int mid){
    vector<int> temp(right-left+1);//创建一个临时数组来储存数据
    int i=left;
    int j=mid+1;
    int k=0;//数组的下标
    while(i<=mid&&j<=right){//一一对比，再放进临时数组里
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
        }
    }
    //如果还有剩的就直接全部加入临时数组，因为左右半区已经是有序的了
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=right){
        temp[k++]=arr[j++];
    }
    //把临时数组的值更新回原数组
    for(int p=0;p<temp.size();p++){
        arr[left+p]=temp[p];//只对参与的那部分更新
    }
}
//对数组进行分割再合并
void mergesort(vector<int>& arr,int left,int right){
    if(left>=right){
        return;
    }//如果分割到只剩一个数就停止
    int mid=left+(right-left)/2;//取中值，这样的写法是为了防止left+right溢出
    mergesort(arr,left,mid);//对左半区分割合并
    mergesort(arr,mid+1,right);//对右半区分割合并
    merge(arr,left,right,mid);//把左右半区合并
}
//把这个数组打印出来
void  printarr(const vector<int>& arr){
    for(int num:arr){//快捷写法等价于for(int num=0;num<arr.size();i++)
        cout<<num<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr={54,321,326,329,713,1120,125,410,517};
    printarr(arr);
    mergesort(arr,0,arr.size()-1);
    printarr(arr);
    return  0;
}