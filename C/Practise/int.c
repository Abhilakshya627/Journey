#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i,j,t,s=0,neg=0,z=0;
    int *a;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&a[i]);
        if(a[i]<0)
        neg++;
        else if(a[i]==0)
        z++;
    }
    while(neg!=0){
        for(i=0;i<n;i++){
            if(a[i]<0){
                t=a[i];
                neg--;
                for(j=i;j>s;j--){
                    a[j]=a[j-1];
                }
                a[0+s++]=t;
            }
        }
    }
    while(z!=0){
        for(i=0;i<n;i++){
            if(a[i]==0){
                z--;
                for(j=i;j>s;j--){
                    a[j]=a[j-1];
                }
                a[0+s++]=0;

            }
        }
    }
    printf("The Rearranged Array is : ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    free(a);

    return 0;
}