/*
    *
   **
  ***
 ****
*****
*/

#include <iostream>
using namespace std;

int main(){
    int n,i=1;
    cout<<"Enter number of rows : ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=n-i;j>0;j--)
        {
            cout<<" ";
        }
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    while (i<=n)
    {
        
        int j=n-i;
        while(j>0)
        {
            cout<<" ";
            j--;
        }
        j=1;
        while(j<=i)
        {
            cout<<"*"; 
            j++;
        }
        cout<<endl;
        i++;
    }
    

    return 0;
}