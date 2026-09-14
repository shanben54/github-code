#include<stdio.h>

#define MAXSIZE 10000
typedef int Status;
#define TRUE 1
#define FALSE 0

//顺序表结构
typedef struct{
    int r[MAXSIZE+1];//顺序表数组
    int length;//数组长度
}SqList;

//交换数组元素
void swap(SqList *L,int i,int j){
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}

//冒泡排序基础版
//其实就是交换排序，寻找比自己小的元素然后直接交换，但是这样交换会比较混乱，有些数据可能被交换到最后去
void BubbleSort0(SqList *L){
    int i,j;
    for(i=1;i<L->length;i++){
        for(j=i+1;j<=L->length;j++){//遍历之后的元素
            if(L->r[i]>L->r[j]){//如果更小就交换
                swap(L,i,j);
            }
        }
    }
}

//冒泡排序
//正宗冒泡排序，和相邻元素对比交换，更为有序
void BubbleSort(SqList *L){
    int i,j;
    for(i=1;i<L->length;i++){
        for(j=L->length-1;j>=1;j--){//从后往前遍历
            if(L->r[j]>L->r[j+1]){//如果比前一个大就交换
                sawp(L,j,j+1);
            }
        }
    }
}

//冒泡排序优化
//设置了一个flag变量用于确认当前序列是否有序，如果已经有序了后续也不用再循环了
void BubbleSort2(SqList *L){
    int i,j;
    Status flag=TRUE;//标记变量
    for(i=1;i<L->length&&flag;i++){//如果标记为TRUE才进行循环
        flag=FALSE;//先初始化为否
        for(j=L->length-1;j>=i;j--){
            if(L->r[j]>L->r[j+1]){
                swap(L,j,j+1);
                flag=TRUE;//交换后才更改flag的值，如果循环过后一次都没有交换，说明序列已经有序
            }
        }
    }
}

//简单选择排序
//基础版冒泡排序的改进版，找到更小的先不交换，先记录下来，每次只把最小的交换到前面去
void SelectSort(SqList *L){
    int i,j,min;
    for(i=1;i<L->length;i++){
        min=i;//最小值的下标先记录为i
        for(j=i+1;j<=L->length;j++){
            if(L->r[min]>L->r[j]){
                min=j;//找到更小的值就更新min下标
            }
        }
        if(i!=min){
            swap(L,i,min);//最终把最小值和i交换
        }
    }
}

//直接插入排序
//像扑克牌插牌那样，最前面的是已经排好的序列，如果后面有更小的值，就不断往前，然后插入在序列里面
void InsertSort(SqList *L){
    int i,j;
    for(i=2;i<=L->length;i++){//i从2开始，i前面的是已经排序好的序列
        if(L->r[i]<L->r[i-1]){//如果i小于i-1，说明i需要插入进序列里面
            L->r[0]=L->r[i];//标记，用于记录i的值
            for(j=i-1;L->r[j]>L->r[0];j--){
                L->r[j+1]=L->r[j];//如果比i的值大就后移让出位置
            }
            L->r[j+1]=L->r[0];//移动完之后j+1的位置是空的，用于插入i
        }
    }
}

//希尔排序
//插入排序的改良版，先设定增量，把一定增量差的元素进行排序，整体达到基本有序，再一步步减少增量，最后完整进行一次插入排序
void ShellSort(SqList *L){
    int i,j,k=0;
    int increment=L->length;//增量，先定义为序列长度
    do{
        increment=increment/3+1;//增量序列
        for(i=increment+1;i<=L->length;i++){//从某个值开始一直到序列尾
            if(L->r[i]<L->r[i-increment]){//和前增量元素对比
                L->r[0]=L->r[i];
                for(j=i-increment; j>0&&L->r[0]<L->r[j]; j-=increment){
                    L->r[j+increment]=L->r[j];
                }
                L->r[j+increment]=L->r[0];
                //这几步操作其实是交换两个元素，和插入排序的操作很像，但是不是加减1，而是增量increment
                //当增量为1时，这其实就是插入排序
            }
        }
    }
    while(increment>1);//增量最后一个值是1
}

//堆调整函数
void HeapAdjust(SqList *L,int s,int m){
    int temp,j;
    temp=L->r[s];
    for(j=2*s;j<=m;j*=2){
        if(j<m&&L->r[j]<L->r[j+1]){
            ++j;
        }
        if(temp>=L->r[j]){
            break;
        }
        L->r[s]=L->r[j];
        s=j;
    }
    L->r[s]=temp;
}

//堆排序
void HeapSort(SqList *L){
    int i;
    for(i=L->length/2;i>0;i--){
        HeapAdjust(L,i,L->length);
    }
    for(i=L->length;i>1;i--){
        swap(L,1,i);
        HeapAdjust(L,1,i-1);
    }
}

//归并排序

void Merge(int SR[],int TR[],int i,int m,int n){
    int j,k,l;
    for(j=m+1,k=i;i<=m&&j<=n;k++){
        if(SR[i]<SR[j]){
            TR[k]=SR[i++];
        }else{
            TR[k]=SR[j++];
        }
    }
    if(i<=m){
        for(l=0;l<=m-i;l++){
            TR[k+l]=SR[i+l];
        }
    }
    if(j<=n){
        for(l=0;l<=n-j;l++){
            TR[k+l]=SR[j+l];
        }
    }
}

void MSort(int SR[],int TR1[],int s,int t){
    int m;
    int TR2[MAXSIZE+1];
    if(s==t){
        TR1[s]=SR[s];
    }else{
        m=(s+t)/2;
        MSort(SR,TR2,s,m);
        MSort(SR,TR2,m+1,t);
        Merge(TR2,TR1,s,m,t);
    }
}

void MergeSort(SqList *L){
    MSort(L->r,L->r,1,L->length);
}