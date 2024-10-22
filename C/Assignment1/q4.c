#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i,f,j,flg;
    int *a;
    printf("Enter the number of elements: ");   
    scanf("%d",&n); 
    a=(int*)malloc(n*sizeof(int));
    printf("Enter array elements :\n");
    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&a[i]);  
    }
    printf("Frequencies of the elements are :\n");
    for(i=0;i<n;i++){
        f=1;flg=1;
        for(j=i-1;j>=0;j--){
            if(a[i]==a[j]){
                flg--;
                break;
            }
        }
        if(flg==1){
            for(j=i+1;j<n;j++){
                if(a[i]==a[j])
                f++;
            }
            printf("%d : %d\n",a[i],f);
        }
    }
    free(a);
    
    return 0;
}