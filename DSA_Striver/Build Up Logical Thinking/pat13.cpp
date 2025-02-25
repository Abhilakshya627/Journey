/*
1
23
456
78910
*/
#include <iostream>
using namespace std;

int main(){
    int n,c=0;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<++c<<" ";
        }
        cout<<endl;
    }

    return 0;
}