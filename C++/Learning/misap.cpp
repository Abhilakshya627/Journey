#include<iostream>
using namespace std;

int main(){
    int i,n,d,mi,nm;
    cout<<"Enter number of terms : ";
    cin>>n;
    int a[n];
    cout<<"Enter series in order : \n";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    d=a[1]-a[0];
    cout<<"Series with no missing term :\n";
    for(i=0;i<n-1;i++){
        if(a[i+1]-a[i]!=d){
            int t=a[i];
            while(t+d!=a[i+1]){
                cout<<t<<" ";
                t+=d;
            }
            cout<<t+d<<" ";
        }
        cout<<a[i]<<" ";
    }

    return 0;
}