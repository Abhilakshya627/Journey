//Program to find sum of n natural numbers using while loop
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter value of n : ";
    cin>>n;
    int i=1,s=0;
    while(i<=n)
    {
        s+=i;
        i++;
    }
    cout<<"Sum of "<<n<<" natural numbers is : "<<s<<endl;

    return 0;
}