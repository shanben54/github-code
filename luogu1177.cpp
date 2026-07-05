//三大基础排序和快速排序
#include<bits/stdc++.h>
using namespace std;
int a[100];
int n;
//快速排序，用了分治的思想
void qsort(int a[],int l,int r){
    int flag=a[(r+l)/2],i=l,j=r,tmp;
    do{
        while(a[i]<a[flag]) i++;
        while(a[j]>a[flag]) j--;
        if(i<=j){
            tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
            i++,j--;
        }
    }while(i<=j);
    if(l<j) qsort(a,l,j);
    if(r>i) qsort(a,i,r);
}
//选择排序，我觉得最好用的，因为非常简单
void xuanzepaixu(){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i]){
                int tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
}
//冒泡排序
void maopaopaixu(){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                int tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
    }
}
//插入排序
void charupaixu(){
    for(int i=1;i<n;i++){
        int now=a[i],j;
        for(j=i-1;j>=0;j--){
            if(a[j]>now){
                a[j+1]=a[j];
            }
            else break;
        }
        a[j+1]=now;
    }
}
