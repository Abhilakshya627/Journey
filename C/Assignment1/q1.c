#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,n,e=0,o=0;
    int *a;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("Enter elements of the array :\n");
    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",a+i);
        if(a[i]%2==0)
        e++;
        else
        o++;
    }
    printf("Total number of even numbers : %d\n",e);
    printf("Total number of odd numbers : %d\n",o);
    free(a);

    return 0;
}