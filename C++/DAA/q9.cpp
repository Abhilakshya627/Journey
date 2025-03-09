//Given an array of integers, design an algorithm and implement it using a program to sort an array by dividing the array into two subarrays and combining these subarrays after sorting each one of them. Your program should also find number of comparisions and inversions during the sorting of array.
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high, int& comparisons, int& inversions) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        } else {
            inversions += (high - j); // Count inversions: all elements from i+1 to high are greater than arr[j]
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, int& comparisons, int& inversions) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons, inversions);
        quickSort(arr, low, pi - 1, comparisons, inversions);
        quickSort(arr, pi + 1, high, comparisons, inversions);
    }
}

int main(){
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the elements of the array: ";
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        int comparisons = 0,inversions = 0;
        quickSort(arr, 0, n - 1, comparisons, inversions);
        cout << "Sorted array: ";
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "Comparisons: " << comparisons << endl;
        cout << "Inversions: " << inversions << endl;
    }

    return 0;
}