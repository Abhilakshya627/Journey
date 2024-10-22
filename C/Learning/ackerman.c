#include<stdio.h>

int ack(int m,int n){
    int ans;
    if(m==0)
    ans=n+1;
    else if(n==0)
    ans=ack(m-1,1);
    else
    ans=ack(m-1,ack(m,n-1));
    return ans;
}

void main(){
    int m,n;
    printf("Enter the value of m: ");
    scanf("%d",&m);
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("The value of ack(%d,%d) is %d\n",m,n,ack(m,n));
}