//Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether a given key element is present in the array or not. Also, find the total number of comparisons for each input case. (Time Complexity = O(log2n), where n is the size of input).
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int key, int& comp){
    int low = 0, high = arr.size()-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == key){
            comp++;
            return mid;
        }
        else if(arr[mid] < key){
            comp++;
            low = mid + 1;
        }
        else{
            comp++;
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int t;
    cout<<"Abhilakshya Bhatt\nRoll Number: 03\nUniversity Roll Number: 2023975\n";
    cout<<"Enter the number of test cases: ";
    cin >> t;
    while(t--){
        int n,comp=0;
        cout<<"Enter the size of array: ";
        cin >> n;
        vector<int> arr(n);
        cout<<"Enter the elements of array: ";
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        int key;
        cout<<"Enter the key element: ";
        cin >> key;
        int index = binarySearch(arr, key, comp);
        if(index == -1){
            cout<<"Not Present "<<comp<<endl;
        }
        else{
            cout<<"Present "<<comp<<endl;
        }
    }

    return 0;
}