#include <iostream>
using namespace std;

int main()
{
    int a,b;
    cout<<"Enter the value of a and b"<<endl;
    cin>>a>>b;
    if(a<b)
    {
        cout<<"a is smaller than b"<<endl;
    }
    else if(b<a)
    {
        cout<<"b is smaller than a"<<endl;
    }
    else
    {
        cout<<"a and b are equal"<<endl;
    }
    
    return 0;
}