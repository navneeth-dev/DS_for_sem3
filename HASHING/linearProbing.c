#include<stdlib.h>
#include<stdio.h>

int table[100];

// Hash Function: x is the number of elements

int hash(int key, int x) {
    return key % x;
}

void insert(int key,int x){
    int value = hash(key,x);
    
    // if the slot is empty, then we directly insert the key
    
    if(table[value]==-999) table[value] = key;
    
    // Resolving collision via linear probing
    
    else{
        int i = 1;
        while(table[value]!=-999 && i<x){
            value = hash(value+i,x);
            i++;
        }
        if(table[value]==-999) table[value]=key;
        else printf("Table full\n");
    }
}

void search(int key,int x){
    int value = hash(key,x);
    
    // If key is present in the slot itself, then we print it
    
    if(table[value]==key) printf("Key %d found\n",key);
    else{
        int i = 1;
        
        // Otherwise we search through the array
        
        while(table[value]!=key && i<x){
            value = hash(value+i,x);
            i++;
        }
        if(table[value]==key) printf("Key %d found\n",key);
        else printf("Key %d not found\n",key);
    }
}

void display(int n){
    for(int i=0;i<n;i++){
        printf("%d ",table[i]);
    }
}

int main() {
    int n, ele;
    printf("Enter the number of elements to be inserted\n");
    scanf("%d", &n);
    
    // We initialize all objects of the structure to have the data as -999
    // It is easier to work with this way
    
    for (int i = 0; i < n; i++) {
        table[i] = -999;
    }
    
    printf("Enter the key values\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &ele);
        insert(ele, n);
    }
    
    display(n);
    
    printf("Enter the element you want to search");
    scanf("%d",&ele);
    search(ele,n);

    return 0;
}
