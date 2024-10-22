#include<iostream>
using namespace std;

int main(){
    int a[10]={1,2,4,6,8,8,9,6,4,3};
    int s=0,e=9;
    while(s<e){
        int mid=s+(e-s)/2;
        if(a[mid]<a[mid+1] || a[mid]==a[mid+1])
        s=mid+1;
        else
        e=mid;
    }
    cout<<"Peak Element is at "<<s<<" position"<<endl;

    return 0;
}