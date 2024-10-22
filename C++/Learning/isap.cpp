#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of terms in series : ";
    cin>>n;
    int a[n]; 
    for(int i=0;i<n;i++){
        cout<<"Enter "<<i+1<<"th term : ";
        cin>>a[i];
    }
    cout<<"Given Series : ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int d=a[1]-a[0],f=0;
    for(int i=1;i<n-1;i++){
        if(a[i+1]-a[i]!=d){
            cout<<"Not an arithmetic progression series";
            f=1;
            break;
        }
    }
    if(f==0)
    cout<<"Arithmetic progression series";
    return 0;
}