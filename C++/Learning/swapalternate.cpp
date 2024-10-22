#include<iostream>
using namespace std;

#define MAX 100

void swap(int a[],int n){
    int temp;
    for(int i=0;i<n-1;i+=2){
        if((i+1)!=n){
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
        }
    }
}

int main(){
    int n,i,a[MAX];
    cout<<"Enter size of array : ";
    cin>>n;
    cout<<"Enter elements of array : \n";
    for(i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<" : ";
        cin>>a[i];
    }
    swap(a,n);
    cout<<"Array after swapping : ";
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}