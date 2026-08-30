#include<stdio.h>

//顺序表查找
int Sequential_Search(int *a,int n,int key){//a为数组，n为数组长度，key为要查找的关键字
    int i;
    for(i=1;i<=n;i++){
        if(a[i]==key){
            return i;
        }
    }
    return 0;
}

//顺序表查找优化
//上一个代码，每次循环时i都要和n比较一下，这里优化后不需要每次比较i和n
int Sequential_Search2(int *a,int n,int key){
    int i;
    a[0]=key;//哨兵
    i=n;//从尾开始循环
    while(a[i]!=key){
        i--;
    }
    return i;//返回0说明查找失败
}

//有序表查找

//折半查找(二分查找)
int Binary_Search(int *a,int n,int key){//a必须已经从小到大排序好
    int low,high,mid;
    low=1;//定义左边为第一个元素
    high=n;//定义右边为最后一个元素
    while(low<=high){
        mid=(low + high)/2;//折半
        if(key<a[mid]){
            high=mid-1;//如果中值大了就去左边查找
        }else if(key>a[mid]){
            low=mid+1;//如果中值小了就去右边查找
        }else{
            return mid;//中值等于关键字就返回中值
        }
    }
    return 0;
}

//插值查找
//和折半排序的区别在于求mid的值，折半排序如果数据非常偏向于某一侧的时候效率较低
//插值排序在计算mid的值时根据key的值在a[high]-a[low]这一跨度的占比来计算mid，效率会更高
int Interpolation_Search(int *a,int n,int key){
    int low,high,mid;
    low=1;//定义左边为第一个元素
    high=n;//定义右边为最后一个元素
    while(low<=high){
        mid=low+(high-low)*(key-a[low])/(a[high]-a[low]);//根据key值占比来计算mid
        if(key<a[mid]){
            high=mid-1;//mid值大了更改high的值
        }else if(key>a[mid]){
            low=mid+1;//mid值小了就更改low的值
        }else{
            return mid;//mid值等于关键字就返回mid
        }
    }
    return 0;
}