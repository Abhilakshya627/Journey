#include <iostream>
using namespace std;

int firstOccurrence(int a[],int n,int k){
    int s=0,e=n-1,mid=s+(e-s)/2,ans=-1;
    while(s<=e){
        if(a[mid]==k){
            ans=mid;
            e=mid-1;
        }
        else if(a[mid]>k){
            e=mid-1;
        }
        else {
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int lastOccurence(int a[],int n,int k){
    int s=0,e=n-1,mid=s+(e-s)/2,ans=-1;
    while(s<=e){
        if(a[mid]==k){
            ans=mid;
            s=mid+1;
        }
        else if(a[mid]>k){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int main(){
    int k,arr[10]={0,2,2,2,3,5,5,7,8,9},f,l,total;
    cout<<"Enter value of key : ";
    cin>>k;
    f=firstOccurrence(arr,10,k);
    l=lastOccurence(arr,10,k);
    total=l-f+1;
    cout<<"First occurrence of "<<k<<" is at index "<<f<<endl;
    cout<<"Last occrence of "<<k<<" is at index "<<l<<endl;
    cout<<"Frequency of "<<k<<" in the array is "<<total<<endl;

    return 0;
}