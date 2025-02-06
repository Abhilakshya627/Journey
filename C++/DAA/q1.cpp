// Dutch National Flag Problem (Sort the Color(LeetCode))
#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n,i,t,j;
    std::cout<<"Enter size of array : ";
    std::cin>>n;
    std::vector<int> a(n);
    std::cout<<"Enter elements of array\n";
    for(i=0;i<n;i++){
        std::cout<<"Enter element "<<i+1<<" : ";
        std::cin>>a[i];
    }
    std::cout<<"Printing array : ";
    for(i=0;i<n;i++){
        std::cout<<a[i]<<" ";
    }
    std::cout<<"\n";
    for(i=0,j=n-1;i<n && j>=0;i++,j--){
        if(a[i]>a[j] && i<j){
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }else if(a[j]==0){
            a[j]=a[0];
            a[0]=0;
            i--;
        }else if(a[i]==0){
            a[i]=a[0];
            a[0]=0;
            j++;
        }else if(a[i]==a[j]){
            i--;
        }
    }
    std::cout<<"Printing sorted array : ";
    for(i=0;i<n;i++){
        std::cout<<a[i]<<" ";
    }
    
    return 0;
}