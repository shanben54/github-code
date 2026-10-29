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

    return 0;
}