#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i,d;
    int *a;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("Enter elements : \n");
    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&a[i]);
    }
    
}