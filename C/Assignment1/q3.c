#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i;
    int *a;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("Enter array elements :\n");
    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",a+i);
    }
    for(i=0;i<n/2;i++){
        a[i]=a[i]+a[n-1-i];
        a[n-1-i]=a[i]-a[n-1-i];
        a[i]=a[i]-a[n-1-i];
    }
    printf("Rearranged Array : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    free(a);

    return 0;
}