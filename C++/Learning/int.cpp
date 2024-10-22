#include <iostream>
using namespace std;

int main(){
    int n,s=0,neg=0,z=0,i,j,t;
    int *a;
    cout<<"Enter number of elements : ";
    cin>>n;
    a=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<" : ";
        cin>>a[i];
        if(a[i]<0)
        neg++;
        else if(a[i]==0)
        z++;
    }
    for(i=0;i<n;i++){
        if(a[i]<0){
            t=a[i];
            if(s!=neg)
            {
                for(j=i;j>s;j--){
                a[j]=a[j-1];
                }
                a[s++]=t;

            }
        }
    }
    s=0;
    for(i=neg;i<n;i++){
        if(a[i]==0)
        {
            for(j=i;j>neg+s;j--){
                a[j]=a[j-1];
            }
            a[neg+s++]=0;
        }
    }   
    cout<<"The array is : ";
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    } 

    return 0;
}