#include<iostream>
using namespace std;

void main(){
    int n,i=0,bi[32],n1=0,nums;
    cout<<"Enter a number : ";
    cin>>n;
    nums=n;
    while(n>0){
        bi[i]=n%2;
        n/=2;
        if(bi[i]==1)
        n1++;
        i++;
        if(n1>1)
        break;
    }
    if(n1==1)
    cout<<nums<<" is in power of two"<<endl;
    else
    cout<<nums<<" is not in power of two"<<endl;
}