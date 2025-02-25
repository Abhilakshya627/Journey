/*
A
BB
CCC
DDDD
*/
#include <iostream>
using namespace std;

int main(){
    int n;
    char c;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for(int i=0;i<n;i++){
        c = 'A' + i;
        for(int j=0;j<=i;j++){
            cout<<c<<" ";
        }
        cout<<endl;
    }

    return 0;
}