#include <stdlib.h>
#include <stdio.h>

// S = Source 
// A = Auxillary
// D = Destination

// Trick: 1. in the top it is SAD
//        2. 1st rec call it is SDA
//        3. 2nd rec call it is ASD

void Hanoi(int n, char S, char A, char D){
    if(n == 1)
        printf("Move 1 disc from %c to %c\n", S, D);
    else{
        Hanoi(n - 1, S, D, A);
        printf("Move %d disc from %c to %c\n", n, S, D);
        Hanoi(n - 1, A, S, D);
    }
}

int main(){
    char S = 'A', A = 'C', D = 'B';
    Hanoi(3, S, A, D); 
    return 0;
}

