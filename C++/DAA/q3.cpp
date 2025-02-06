//Find peak element in an array
#include <iostream>
#include <vector>
#include <cmath>

int main(){
    std::vector<int> a = {1,2,3,4,5,6,7,8,9,10,7,8,9};
    int n = a.size();
    int low = 0, high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if((mid==0 || a[mid]>=a[mid-1]) && (mid==n-1 || a[mid]>=a[mid+1])){
            std::cout<<"Peak element found at index: "<<mid;
            return 0;
        }
        else if(mid>0 && a[mid-1]>a[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    return 0;
}