//Given an usorted array of integers, design an algorithm and implement it using a program to find kth smallest or largest element in the array. (Time Complexity = O(n))
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int left, int right, int pivotIndex) {
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]); 
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            swap(arr[storeIndex], arr[i]);
            storeIndex++;
        }
    }
    swap(arr[storeIndex], arr[right]); 
    return storeIndex;
}

int quickSelect(vector<int>& arr, int left, int right, int k) {
    if (left == right) { 
        return arr[left]; 
    }
    int pivotIndex = left + rand() % (right - left + 1);
    pivotIndex = partition(arr, left, right, pivotIndex);
    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickSelect(arr, left, pivotIndex - 1, k);
    } else {
        return quickSelect(arr, pivotIndex + 1, right, k);
    }
}

int main(){
    int t;
    cout<<"Abhilakshya Bhatt\nRoll Number: 03\nUniversity Roll Number: 2023975\n";
    cout<<"Enter the number of test cases: ";
    cin>>t;
    while(t--){
        int n, k;
        cout<<"Enter the size of array: ";
        cin>>n;
        vector<int> arr(n);
        cout<<"Enter the elements of array: ";
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        cout<<"Enter the value of k: ";
        cin>>k;
        cout << k << "th smallest element is: " << quickSelect(arr, 0, arr.size() - 1, k - 1)<< endl;
    }

    return 0;
}