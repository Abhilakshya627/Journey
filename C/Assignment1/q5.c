#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i,d,flg;
    int *a;
    printf("Enter the number of elements: ");   
    scanf("%d",&n); 
    a=(int*)malloc(n*sizeof(int));
    printf("Enter array elements :\n");
    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&a[i]);  
    }
    d=a[1]-a[0];
    for(i=2;i<n;i++){
        if(a[i]-a[i-1]!=d){
            flg=1;
            break;  
        }
    }
    if(flg==1)
    printf("The given series is not AP\n");
    else
    printf("The given series is AP\n");
    printf("Given Series : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    free(a);

    return 0;
}