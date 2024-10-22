/*
*
**
***
****
*/

#include <iostream>
using namespace std;

int main()
{
    int n,i=1;
    cout<<"Enter number of rows : ";
    cin>>n;
    while(i<=n)
    {
        int j=1;
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