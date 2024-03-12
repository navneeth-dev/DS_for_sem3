#include <stdio.h>
#define m 7

int arr[7];

int hash1(int data){
    return data%m;
}

void insert(int data) {
    int val = hash1(data);
    int i = 0;
    while (arr[val] != -1) {
        i++;
        val = (val + i * i) % 7;
        if (i >= m) {
            printf("Error: Hash table is full.\n");
            return;
        }
    }
    arr[val] = data;
}



void display() {
    for (int i = 0; i < 7; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int search(int data) {
    int val = hash1(data);
    int i = 0;
    while (arr[val] != data) {
        if (i >= m)
            return -1;
        i++;
        val = (val + i * i) % 7;
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
    insert(1);

    printf("%d\n",search(22));
    
    display();
}
