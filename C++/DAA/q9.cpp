//Given an unsorted array of positive integers, design an algorithm and implement it using a program to find whether there are any duplicate elements in the array or not. (use sorting) (Time Complexity = O(n log n))
#include<bits/stdc++.h>
using namespace std;

string hasDuplicates(vector<int> arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n - 1; i++){
        if(arr[i] == arr[i + 1]){
            return "YES";
        }
    }
    return "NO";
}

int main(){
    int t;
    cout<<"Abhilakshya Bhatt\nRoll Number: 03\nUniversity Roll Number: 2023975\n";
    cout<<"Enter the number of test cases: ";
    cin>>t;
    while(t--){
        int n;
        cout<<"Enter the size of array: ";
        cin>>n;
        vector<int> arr(n);
        cout<<"Enter the elements of array: ";
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        cout<<hasDuplicates(arr)<<endl;
    }

    return 0;
}