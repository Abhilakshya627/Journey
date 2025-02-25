/*
1
12
123
1234
*/
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter numbet of rows: ";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<j+1<<"";
        }
        cout<<endl;
    }

    return 0;
}