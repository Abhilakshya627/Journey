/*
1234        4321
1234        4321
1234        4321
1234        4321
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
        while(j<=n)
        {
            cout<<j++;
        }
        cout<<"\t\t";
        j=1;
        while(j<=n)
        {
            cout<<n-j+1;
            j++;
        }
        cout<<endl;
        i++;
    }

    return 0;
}