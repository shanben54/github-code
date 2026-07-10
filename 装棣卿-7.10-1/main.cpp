#include<stdio.h>
#include"swap.h"
int main(){
    int x=10,y=20;
    printf("Before:x=%d,y=%d\n",x,y);
    swap(&x,&y);
    printf("After:x=%d,y=%d\n",x,y);
    return 0;
}