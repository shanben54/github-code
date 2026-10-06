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

//堆排序
//高级版的选择排序，但是利用了堆来找到未排序数据里的最大值
//堆就是完全二叉树，这里不用定义新的结构，而是利用完全二叉树的性质来进行调整
//第i个元素的孩子就是2i和2i+1，长度为n的数组的最大中间结点就是[n/2]，[i]表示不大于i的最大整数
void HeapSort(SqList *L){
    int i;
    for(i=L->length/2;i>0;i--){//长度除于2就是中间结点的最大下标，倒着一步步调整，可以保证调整的时候结点的孩子是子树里的最大数据
        HeapAdjust(L,i,L->length);//先对所以中间结点进行堆调整，最后调整根结点，这样就构建好了大顶堆
    }
    //再根据大顶堆进行排序
    for(i=L->length;i>1;i--){
        swap(L,1,i);//先把首位结点交换，其实就是把最大的数据放到数组末尾了
        HeapAdjust(L,1,i-1);//再对根结点进行堆调整，找到最大的数据，注意调整的范围，此时数组末尾已经是排序好的数据
    }
}

//堆调整函数
//以s为根结点，遍历s的子树，把子树里面最大的值调整为s结点
//这里的树并没有在数据里体现出来，而是运用完全二叉树的性质，根据数据下标来调整
//由于也会对s的孩子进行堆调整，所以s的孩子就是子树里最大的值
//如果孩子更大就赋值给根结点，然后s指向孩子结点，再继续遍历，将较大的数据都往前移，最后将初始根结点的值赋值给最后一个操作的结点
//这个过程有点像插入排序，先找个标兵记录数据，然后更大的数据都往前移动，最后把初始数据放在最后
void HeapAdjust(SqList *L,int s,int m){//将L[s...m]调整成大顶堆
    int temp,j;
    temp=L->r[s];//标兵，记录初始值
    for(j=2*s;j<=m;j*=2){//沿s的子树进行查找
        if(j<m&&L->r[j]<L->r[j+1]){//如果右孩子更大就指向右孩子
            ++j;
        }
        if(temp>=L->r[j]){
            break;//如果小于s的值就略过
        }
        L->r[s]=L->r[j];//原本s的位置的数据更新为更大的j
        s=j;//s更新为j
    }
    L->r[s]=temp;//把空的位置赋值为初始s的值
}

//归并排序
//把数组进行拆半，对这两半继续归并排序使得他们有序，再把这两半合并成最终有序的数组
void MergeSort(SqList *L){
    MSort(L->r,L->r,1,L->length);
}

//对数组进行归并排序
//先开辟新的数组用于记录分半的数据，再继续递归，直到只剩一个数据，然后返回上一层，将平分的两个数组进行合并，再继续上一层，直到最初
void MSort(int SR[],int TR1[],int s,int t){//将数组SR归并排序后放入数组TR1里，s,t表示需要排序的范围
    int m;
    int TR2[MAXSIZE+1];//开辟新数组用于记录平分的数据
    if(s==t){
        TR1[s]=SR[s];//如果范围为1，那就直接吧SR这个元素放入TR1
    }else{
        m=(s+t)/2;//将SR平分为SR[s...m]和SR[m+1...t]
        MSort(SR,TR2,s,m);//对左半边递归归并排序
        MSort(SR,TR2,m+1,t);//对右半边递归归并排序
        Merge(TR2,TR1,s,m,t);//再把两半边合并排序成最终数组
    }
}

//对两半有序的数组进行合并
//就是对数组两半的元素进行遍历，比较大小，更小的就放入新数组，两半数组本身是有序的，然后比较后得到的新数组就是有序的
void Merge(int SR[],int TR[],int i,int m,int n){//将数组SR[i...m]和SR[m+1...n]合并排序后放入数组TR
    int j,k,l;
    for(j=m+1,k=i;i<=m&&j<=n;k++){//i是左半数组的下标，j是右半数组的下标，k是数组TR的下标
        if(SR[i]<SR[j]){//i更小就先放入i
            TR[k]=SR[i++];//i增加
        }else{//j更小就放入j
            TR[k]=SR[j++];//j增加
        }
    }
    //处理剩余的元素
    if(i<=m){
        for(l=0;l<=m-i;l++){
            TR[k+l]=SR[i+l];//i还剩就继续添加直到m
        }
    }
    if(j<=n){
        for(l=0;l<=n-j;l++){
            TR[k+l]=SR[j+l];//j还剩就继续添加直到n
        }
    }
}

//归并排序的高阶版本，不调用递归
//不需要调用递归进行拆半归并，也不需要每次都开数组记录拆半的数据，而是只多开一个数组，和原数组一起反复进行归并
//在不递归的情况下利用子序列的长度来进行归并，这样也不用把数组不断拆半成最小单元了，而是根据序列长度，直接两两归并
//然后再把更大的序列两两归并，两个数组反复将数据归并排序进另一个数组里
//哪怕放入新数组的时候已经排好序了，最后再归并一次，也会把数据直接复制回原数组
void MergeSort2(SqList *L){
    int* TR=(int*)malloc(L->length*sizeof(int));//申请额外空间，用于和原数组互相排序合并记录
    int k=1;
    while(k<L->length){//k表示子序列的长度
        MergePass(L->r,TR,k,L->length);//将子序列合并进新数组记录
        k=2*k;//子序列长度翻倍
        MergePass(TR,L->r,k,L->length);//将新数组的子序列合并回原数组，哪怕到最后不合并，也会把新数组的数据复制回原数组
        k=2*k;//子序列长度翻倍
    }
}

//将原数组的子序列合并进新数组
void MergePass(int SR[],int TR[],int s,int n){//将SR中相邻长度为s的子序列归并进TR里，n为SR长度
    int i=1;
    int j;
    while(i<=n-2*s+1){//i后面至少还要有两个s长度的空间才进行子序列两两归并
        Merge(SR,TR,i,i+s-1,i+2*s-1);//把长度为s的两个子序列两两归并
        i=i+2*s;//i增加两个s长度，进行下一组子序列归并
    }
    if(i<n-s+1){//i到s之间大于s，说明还可以构成两个子序列，哪怕最后一个子序列长度没有s
        Merge(SR,TR,i,i+s-1,n);//归并最后两个子序列
    }else{//若剩余长度不满s，只剩一个子序列
        for(j=i;j<=n;j++){
            TR[j]=SR[j];//把子序列平移进新数组
        }
    }
}

//快速排序
//每次都将数组一分为二，找到枢轴值，让数组基本有序，再不断细分，直到最小单元，最终数组都有序
void QuickSort(SqList *L){
    QSort(L,1,L->length);
}

//对L->r[low,high]进行快速排序
void QSort(SqList *L,int low,int high){
    int pivot;//枢轴值
    if(low<high){
        pivot=Partition(L,low,high);//利用函数计算数轴值，将数组一分为二，枢轴值位于中间，左边都比枢轴值小，右边都更大
        QSort(L,low,pivot-1);//对较小半边进行快速排序
        QSort(L,pivot+1,high);//对较大半边进行快速排序
    }
}

//找到L->r[low,high]的枢轴值，并把数据初步排序，小的放枢轴值左边，大的放枢轴值右边
//直接选取第一个元素作为枢轴值，之后从两端遍历数组，左边有大的值或者右边有小的值就交换
//两端的指针不断靠近，最终当两个指针重合，指向枢轴值，此时左边都是比枢轴值小的数据，右边都是比枢轴值大的数据
int Partition(SqList *L,int low,int high){
    int pivotkey;
    pivotkey=L->r[low];//取第一个元素为枢轴值
    while(low<high){
        while(low<high&&L->r[high]>=pivotkey){
            high--;//大的元素才减，high会停在比枢轴值小的元素那
        }
        swap(L,low,high);//交换，把小元素换到枢轴值左边
        while(low<high&&L->r[low]<=pivotkey){
            low++;//小的元素才加，low会停在比枢轴值大的元素那
        }
        swap(L,low,high);//交换，把大的元素换到枢轴值右边
    }
    return low;//最终low等于high，都指向枢轴值
}

//快速排序优化算法
int Partition1(SqList *L,int low,int high){
    int pivotkey;
    
    //对pivotkey选取的优化，取首尾和中间三个数据，进行比较，选取中间值作为枢轴值，这样选取的枢轴值会更靠近中间值一点，提高效率
    int m=low+(high-low)/2;//中间下标
    if(L->r[low]>L->r[high]){
        swap(L,low,high);
    }//确保high>low
    if(L->r[m]>L->r[high]){
        swap(L,high,m);
    }//确保high>m
    if(L->r[m]>L->r[low]){
        swap(L,m,low);
    }//确保low>m
    //这样，此时low下标的值就是这三个数据的中值了
    
    //交换的优化，不让枢轴值参与交换，数据之间只是赋值，这样一轮下来只交换一次，减少交换的次数
    pivotkey=L->r[low];
    L->r[0]=pivotkey;//标兵，先将枢轴值暂存起来
    while(low<high){
        while(low<high&&L->r[high]<pivotkey){
            high--;
        }
        L->r[low]=L->r[high];//只是赋值
        while(low<high&&L->r[low]>pivotkey){
            low++;
        }
        L->r[high]=L->r[low];//赋值
    }
    L->r[low]=L->r[0];//low和high重合时，当前下标的值其实已经被交换过了，是重复数据，把这个下标作为枢轴值的下标
    return low;
}

//处理小数组的优化
//因为快速排序利用递归，当数据比较小的时候，浪费很多空间，大炮打蚊子，所以当数组长度小于一定值时，直接用插入排序，插入排序是简单排序里效率最高的
#define MAXQSORT 7//数组的最小长度
void QSort1(SqList *L,int low,int high){
    int pivot;
    if((high-low)>MAXQSORT){//如果大于最小长度就进行快速排序
        pivot=Partition1(L,low,high);
        QSort1(L,low,pivot-1);
        QSort1(L,pivot+1,high);
    }else{//如果数组长度小直接用插入排序
        InsertSort(L);
    }
}

//递归的优化，减少递归次数
//每次只对左半区调用递归，利用Partition1函数对右半区来排序，不断划分左半区，对左半区递归，最终达到有序，这样递归次数就减少了
void QSort2(SqList *L,int low,int high){
    int pivot;
    if((high-low)>MAXQSORT){
        while(low<high){//进行循环
            pivot=Partition1(L,low,high);//选取枢轴值，进行排序
            QSort2(L,low,pivot-1);//对左半区进行递归
            low=pivot+1;//尾递归，赋值给low，当下次循环的时候，Partition1(L,low,high)其实就是对右半区进行排序了
        }
    }else{
        InsertSort(L);
    }
}