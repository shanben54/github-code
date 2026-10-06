#include<stdio.h>
#include"global.h"
extern int global_var;
int file_static=200;
int main(){
    global_var=300;
    print_global();
    printf("file_static=%d\n",file_static);
    return 0;
}