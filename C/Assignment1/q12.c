#include<stdio.h>
#include<stdlib.h>

void main(){
    int n,*a,*b,*m,i,j;
    printf("Enter size of A and B : ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    b=(int*)malloc(n*sizeof(int));
    m=(int*)malloc(2*n*sizeof(int));
    printf("Enter elements of A\n");
    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&a[i]);
        m[i]=a[i];
    }
    printf("Enter elements of B\n");
    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&b[i]);
        m[i+n]=b[i];
    }
    for(i=0;i<(2*n)-1;i++){
        for(j=i+1;j<2*n;j++){
            if(m[i]>m[j]){
                m[i]=m[i]+m[j];
                m[j]=m[i]-m[j];
                m[i]=m[i]-m[j];
            }
        }
    }
    printf("Sorted and merged array is : ");
    for(i=0;i<(2*n);i++){
        printf("%d ",m[i]);
    }
    free(a);
    free(b);    
    free(m);    
}