#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i,f,j,*a,r=0;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("Enter elements :\n");
    for(i=0;i<n;i++){
        printf("enter element %d : ",i+1);
        scanf("%d",a+i);
    }
    for(i=0;i<n;i++){
        f=0;
        for(j=0;j<n;j++){
            if(a[i]==a[j] && i!=j){
                f++;
                break;
            }
        }
        if(f==0)
        r++;
        if(r==4){
            printf("4th non repeating element is : %d\n",a[i]);
            free(a);
            exit(0);
        }
    }
    free(a);

    return 0;
}    