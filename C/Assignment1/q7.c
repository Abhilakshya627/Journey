#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i,neg=0,z=0,*a,t,j,s=0;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("Enter elements :\n");
    for(i=0;i<n;i++){
        printf("enter element %d : ",i+1);
        scanf("%d",a+i);
        if(a[i]<0)
        neg++;
        else if(a[i]==0)
        z++;
    }
    for(i=0;i<n;i++){
        if(a[i]<0){
            t=a[i];
            if(s!=neg)
            {
                for(j=i;j>s;j--){
                a[j]=a[j-1];
                }
                a[s++]=t;
            }
        }
    }
    s=0;
    for(i=neg;i<n;i++){
        if(a[i]==0)
        {
            for(j=i;j>neg+s;j--){
                a[j]=a[j-1];
            }
            a[neg+s++]=0;
        }
    }
    printf("The array is : ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    free(a);

    return 0;
}