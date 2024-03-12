#include <stdio.h>
#define m1 7
#define m2 4

int arr[7];

int hash2(int data){
    return data%m2;
}

int hash1(int data){
    return data%m1;
}

void insert(int data){
    int val = hash1(data);
    int i = 0;
    while (arr[val] != -1) {
        i++;
        val = (val + i * hash2(data)) % 7;
        if (i >= 7) {
            printf("Error: Hash table is full.\n");
            return;
        }
    }
    arr[val] = data;
}


void display(){
    for(int i =0;i<7;i++&& i<7){
        printf("%d ",arr[i]);
    }
}

int search(int data){
    int val = hash1(data);
    int i = 0;
    while(arr[val]!=data){
        if(i>=7) return -1;
        i++;
        val = (val + i*hash2(data)) % 7;
    }
    return 1;
}

int main()
{
    for(int i = 0;i<7;i++){
        arr[i] = -1;
    }
    
    insert(23);
    insert(23);
    insert(12);
    insert(61);
    insert(61);
    insert(61);

    printf("%d\n",search(12));
    
    display();
}
