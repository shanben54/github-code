#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

//简单插入排序
//如果当前i比前面的更小，就像插牌一样往前动，较大的牌往后移动
template<typename T,typename Cmp>
void InsertionSort(T arr[],int n,Cmp less){
    for(int i=1;i<n;i++){
        if(less(arr[i],arr[i-1])){//先判断对比前一个元素，因为前面已经是有序的，这样不满足就直接跳过省的再移动一次
            T key=arr[i];//标兵，先把当前值记录下来
            int j=i-1;
            while(j>=0&&less(key,arr[j])){//先判断j，防止越界，判断条件是严格小于才移动，这样相等的元素就不会移动改变顺序，比较稳定
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;//j+1就是空位，要插入的地方
        }
    }
}

//快速排序
//不断将区间分割，使区间初步有序，左边都是小的，右边都是大的，一次消灭很多逆序，最终区间分割为最小时达到有序
//分块函数，找到一个位置，使得左边都是小于它的，右边都是大于它的，达到初步有序
template<typename T,typename Cmp>
int Partition(T arr[],int low,int high,Cmp less){
    //三数取中来确定pri，防止数组有序退化成o(n2)
    int mid=low+(high-low)/2;
    if(less(arr[high],arr[low])){
        swap(arr[low],arr[high]);
    }
    if(less(arr[high],arr[mid])){
        swap(arr[mid],arr[high]);
    }
    if(less(arr[low],arr[mid])){
        swap(arr[low],arr[mid]);
    }
    T pri=arr[low];

    //不断移动low和high，将大于pri的元素换到右边，小的元素换到左边，最后low和high重合的位置就是pri
    while(low<high){
        while(low<high&&!less(arr[high],pri)) high--;//条件是大于等于，找到严格小于pri的元素，防止出现和pri值一样的元素然后就卡住
        swap(arr[low],arr[high]);
        while(low<high&&!less(pri,arr[low])) low++;
        swap(arr[low],arr[high]);
    }
    return low;//返回pri的位置
}

//递归分割函数，不断利用分块函数让区间初步有序，再分割去左区间和右区间
template<typename T,typename Cmp>
void QSort(T arr[],int low,int high,Cmp less){
    if(low<high){
        int p=Partition(arr,low,high,less);
        QSort(arr,low,p-1,less);
        QSort(arr,p+1,high,less);
    }
}

//快速排序函数
template<typename T,typename Cmp>
void QuickSort(T arr[],int n,Cmp less){
    QSort(arr,0,n-1,less);
}

long long CountQuickSort(vector<int> a){
    long long c=0;
    QuickSort(a.data(),a.size(),[&c](int x,int y){c++;return x<y;});
    return c;
}

//快速排序优化，三路分割，专门解决含大量重复元素的数组
//[low,lt)是比pri小的,[lt,i)是和pri相等的,[i,gt]是还没判断的,(gt,high]是比pri大的
template<typename T,typename Cmp>
void QSort3(T arr[],int low,int high,Cmp less){
    if(low>=high) return;//区间过小返回
    T pri=arr[low+(high-low)/2];//选取一个标准值，只是选取值而已，这个数据到底在哪不重要，最终会扫描整个数组
    int i=low;
    int gt=high;
    int lt=low;

    while(i<=gt){//当i大于gt说明所有区间都扫描完了
        if(less(arr[i],pri)){
            swap(arr[lt++],arr[i++]);//将等于区间的第一个元素换过来
        }else if(less(pri,arr[i])){
            swap(arr[gt--],arr[i]);//将大于区间的下一个元素换过来，i不用动，因为arr[gt]也是还没判断的
        }else{
            i++;
        }
    }
    QSort3(arr,low,lt-1,less);//对小于区间继续排序
    QSort3(arr,gt+1,high,less);//对大于区间继续排序
}

long long CountQSort3(vector<int> a){
    long long c=0;
    QSort3(a.data(),0,(int)a.size()-1,[&c](int x,int y){c++;return x<y;});
    return c;
}

//堆排序
//下沉函数，如果孩子大于temp，就把孩子换上来，i继续下沉，直到孩子都不大于temp
template<typename T,typename Cmp>
void SiftDown(T arr[],int i,int n,Cmp less){
    T temp=arr[i];
    for(int child=2*i+1;child<n;child=i*2+1){
        if(child+1<n&&less(arr[child],arr[child+1])) child+=1;//哪边孩子更大就用哪边的
        if(!less(temp,arr[child])) break;//如果孩子不大于temp就返回，当数组里的数据全相等的时候大有用，比较一次就直接退出
        arr[i]=arr[child];//把孩子换上来
        i=child;//i继续下沉,此时i的位置是空位
    }
    arr[i]=temp;//最终把temp填回挖的坑去
}

//堆排序函数，大顶堆，升序
//通过大顶堆找到当前数组里最大的值，然后放到数组末尾，继续维护堆，直到排序完成
template<typename T,typename Cmp>
void HeapSort(T arr[],int n,Cmp less){
    //从最后一个非叶结点(n/2-1)开始建立堆，逆向建堆，是为了保证当i建堆的时候，他的孩子已经是堆了
    //如果不是这样，孩子不是堆，子树里的最大值就可能被埋在底下而无法移到最上面
    for(int i=n/2-1;i>=0;i--){
        SiftDown(arr,i,n,less);
    }
    //每次都将当前堆的最大值移动到数组末尾，重新维护堆
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        SiftDown(arr,0,i,less);
    }
}

long long CountHeapSort(vector<int> a){
    long long c=0;
    HeapSort(a.data(),(int)a.size(),[&c](int x,int y){c++;return x<y;});
    return c;
}

//归并排序
//归并函数，将已分别排序好的两段数组进行排序
template<typename T,typename Cmp>
void Merge(T arr[],int low,int mid,int high,T temp[],Cmp less){
    int i=low;
    int j=mid+1;
    int k=low;
    //因为两段数组都已经分别有序了，依次取元素出来比较，较小的就放进temp数组
    while(i<=mid&&j<=high){
        if(less(arr[j],arr[i])){
            temp[k++]=arr[j++];
        }else{//小于或者相等的时候，这样可以保证相等的时候顺序不变，更加稳定
            temp[k++]=arr[i++];
        }
    }
    //处理剩下的元素
    while(i<=mid) temp[k++]=arr[i++];
    while(j<=high) temp[k++]=arr[j++];
    //将元素移回原数组
    for(i=low;i<=high;i++){
        arr[i]=temp[i];
    }
}

//分割的函数，将数组不断递归直至最小(自己就有序，只有一个元素)，然后再调用归并函数进行合并
template<typename T,typename Cmp>
void MSort(T arr[],int low,int high,T temp[],Cmp less){
    if(low>=high) return ;
    int mid=low+(high-low)/2;//将区间分为两半
    MSort(arr,low,mid,temp,less);
    MSort(arr,mid+1,high,temp,less);
    Merge(arr,low,mid,high,temp,less);
}

//归并排序函数
template<typename T,typename Cmp>
void MergeSort(T arr[],int n,Cmp less){
    T* temp=new T[n];//开辟一个数组用于临时储存数据
    MSort(arr,0,n-1,temp,less);
    delete[] temp;
}

long long CountMergeSort(vector<int> a){
    long long c=0;
    MergeSort(a.data(),a.size(),[&c](int x,int y){c++;return x<y;});
    return c;
}

int main(){
    srand(time(0));
    int n=1000;
    vector<int> sam(n,3);
    vector<int> rnd(n);
    vector<int> arc;
    for(int i=0;i<n;i++){
        arc.push_back(i);
        rnd[i]=rand();
    }

    cout<<"随机:"<<CountQuickSort(rnd)<<endl;
    cout<<"有序:"<<CountQuickSort(arc)<<endl;
    cout<<"相同:"<<CountQuickSort(sam)<<endl;

    cout<<"三路-随机:"<<CountQSort3(rnd)<<endl;
    cout<<"三路-有序:"<<CountQSort3(arc)<<endl;
    cout<<"三路-相同:"<<CountQSort3(sam)<<endl;
    
    cout<<"堆排序-随机:"<<CountHeapSort(rnd)<<endl;
    cout<<"堆排序-有序:"<<CountHeapSort(arc)<<endl;
    cout<<"堆排序-相同:"<<CountHeapSort(sam)<<endl;

    cout<<"归并排序-随机:"<<CountMergeSort(rnd)<<endl;
    cout<<"归并排序-有序："<<CountMergeSort(arc)<<endl;
    cout<<"归并排序-相同:"<<CountMergeSort(sam)<<endl;

    return 0;
}