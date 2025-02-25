/*
   A
  ABA
 ABCBA
ABCDCBA
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
        for(int j=0;j<n-i-1;j++){
            cout<<"  ";
        }
        for(int j=0;j<=i;j++){
            cout<<c++<<" ";
        }
        c--;
        for(int j=i-1;j>=0;j--){
            cout<<--c<<" ";
        }
        cout<<endl;
    }

    return 0;
}