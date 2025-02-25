/*
A B C D
A B C 
A B
A
*/
#include <iostream>
using namespace std;

int main(){
    int n;
    char c;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for(int i=0;i<n;i++){
        c='A';
        for(int j=0;j<n-i;j++){
            cout<<c++<<" ";
        }
        cout<<endl;
    }

    return 0;
}