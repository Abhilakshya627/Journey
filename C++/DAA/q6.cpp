//Using an unsorted array, design an algorithm and implement a program using selection to sort an array of elements. Your program should read the elements of an array from the user and use selection to sort the array. Count the number of comparisons and shifts during the sort and print the elements of the sorted array.
#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> arr){
    int n = arr.size();
    int comparisons = 0, shifts = 0;
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
            comparisons++;
        }
        if(i!=minIndex){
            swap(arr[i], arr[minIndex]);
            shifts++;
        }
    }
    cout<<"Sorted array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Comparisons: "<<comparisons<<endl;
    cout<<"Shifts: "<<shifts<<endl;
}

int main(){
    int t;
    cout<<"Enter the number of test cases: ";
    cin>>t;
    while(t--){
        int n;
        cout<<"Enter the number of elements in the array: ";
        cin>>n;
        vector<int> arr(n);
        cout<<"Enter the elements of the array: ";
        for(int i=0; i<n; ++i){
            cin>>arr[i];
        }
        selectionSort(arr);
        cout<<endl;
    }

    return 0;
}