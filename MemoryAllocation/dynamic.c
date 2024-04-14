// Program to show the types of dynamic memory allocation in C

#include <stdlib.h>
#include <stdio.h>

int main(){
    
    int *arr,n,m;
    
    // Using malloc: takes 1 argument
    
    printf("Enter the size\n");
    scanf("%d",&n);
    
    arr = (int *)malloc(sizeof(int)*n);
    free(arr);
    
    // Using calloc: takes 2 arguments
    
    arr = (int *)calloc(sizeof(int),n);
    free(arr);
    
    // Using realloc: takes 2 arguments
    
    arr = (int *)calloc(sizeof(int),n);
    
    printf("Enter the new size\n");
    scanf("%d",&m);
    
    arr = (int *)realloc(arr,m);\
    free(arr);
    
    return 0;
}
