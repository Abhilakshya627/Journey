#include<stdio.h>

int peak(int a[],int n){
    int low=0,high=n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if((mid==0 || a[mid]>=a[mid-1]) && (mid==n-1 || a[mid]>=a[mid+1])){
            return mid;
        }
        else if(mid>0 && a[mid-1]>a[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

int main(){
    int a[10]={1,2,3,4,5,6,7,5,6,7};
    int n=10;
    int index=peak(a,n);
    printf("%d",index);

    return 0;
}