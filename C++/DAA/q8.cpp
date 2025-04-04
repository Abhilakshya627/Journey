//Given an unsorted array of integers, design an algorithm and implement a program to sort this array using selection sort. Your program should also find number of comparisons and number of swaps required.
#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> arr){
    int n = arr.size();
    int comparisons = 0, swaps = 0;
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            comparisons++;
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swaps++;
        swap(arr[i], arr[minIndex]);
    }
    cout<<"Sorted array: ";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nComparisons: "<<comparisons<<"\nSwaps: "<<swaps<<endl;
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
        selectionSort(arr);
    }

    return 0;
}