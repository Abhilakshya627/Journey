#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i,p,d,nmt,c;
    int *a;
    printf("Enter the number of terms in the series : ");
    scanf("%d",&n);
    if(n<3){
        printf("The series must have atleast 3 terms\n");
        return 0;
    }
    a=(int*)malloc(n*sizeof(int));
    printf("Enter the Series :\n");
    for(i=0;i<n;i++){
        printf("Enter %d term : ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Given Series : ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\nSeries with no missing terms : %d %d ",a[0],a[1]);
    d=a[1]-a[0];
    for(i=2;i<n;i++){
        if(d!=(a[i]-a[i-1])){
            p=i-1;
            nmt=(a[i]-a[p])/d;
            c=1;
            while(c<=nmt){
                printf("%d ",(a[p]+(c*d)));
                c++;
            }
        }
        else{
            printf("%d ",a[i]);
        }
    }
    printf("\n");
    free(a);

    return 0;
}