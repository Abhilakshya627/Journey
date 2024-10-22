#include<stdio.h>

void hanoi(int,char,char,char);

void main(){
    int n;
    char a='A',b='B',c='C';
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    hanoi(n,a,b,c);
}

void hanoi(int n,char A,char B,char C){
    if(n==1){
        printf("\nMove disk from %c to %c\n",A,C);
        return;
    }
    hanoi(n-1,A,C,B);
    printf("\nMove disk from %c to %c\n",A,C);
    hanoi(n-1,B,A,C);
}