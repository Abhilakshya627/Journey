//Given an unsorted array of integers, design an algorithm and a program to sort the array using insertion sort. Your program should be able to find number of comparisons and shifts ( shifts - total number of times the array elements are shifted from their place) required for sorting the array.
#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> arr){
    int n = arr.size();
    int comparisons = 0, shifts = 0;
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            comparisons++;
            shifts++;
            arr[j + 1] = arr[j];
            j--;
        }
        shifts++;
        arr[j + 1] = key;
    }
    cout<<"Sorted array: ";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nComparisons: "<<comparisons<<"\nShifts: "<<shifts<<endl;
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
        insertionSort(arr);
    }

    return 0;
}