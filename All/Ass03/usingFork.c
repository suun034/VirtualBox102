#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    fork();
    printf("Hello World, Process ID: %d",getpid());
    return 0;
}