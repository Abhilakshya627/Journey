//Using an unsorted array, design an algorithm and implement a program using insertion sort to sort an array of elements. Your program should read the elements of an array from the user and use insertion sort to sort the array. Count the number of comparisons and shifts during the sort and print the elements of the sorted array.
#include <iostream>
#include <vector>
using namespace std;

void insertSort(vector<int> arr){
    int n = arr.size();
    int comparisons = 0, shifts = 0;
    for(int i=1; i<n; ++i){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            ++shifts;
            ++comparisons;
            --j;
        }
        arr[j+1] = key;
        ++shifts;
    }
    cout<<"Sorted array: ";
    for(int i=0; i<n; ++i){
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
        cout<<"Enter the elements of the array: "<<endl;
        for(int i=0; i<n; ++i){
            cout<<"Enter element "<<i+1<<": ";
            cin>>arr[i];
        }
        insertSort(arr);
    }
}