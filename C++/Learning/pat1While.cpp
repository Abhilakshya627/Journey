/*
****
****
****
****
*/

#include <iostream>
using namespace std;

int main()
{
    int n,i;
    cout<<"Enter no. of rows : ";
    cin>>n;
    i=1;
    while(i<=n)
    {
        int j=1;
        while(j<=n)
        {
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }

    return 0;
}