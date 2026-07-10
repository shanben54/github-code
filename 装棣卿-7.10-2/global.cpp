#include<stdio.h>
#include"global.h"
static int file_static=200;
int global_var=100;
void print_global(){
    printf("global_var=%d\n",global_var);
    printf("file_static=%d\n",file_static);
}