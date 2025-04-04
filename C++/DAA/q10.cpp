//Given an unsorted array of integers, design an algorithm using a program to sort an array of elements by dividing the array into two subarrays and combining these subarrays after sorting each one of them. Your program should also find the number of comparisons and shifts required for sorting the array.
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right, int& comparisons, int& shifts) {
    int n1 = mid - left + 1; 
    int n2 = right - mid;    
    vector<int> L(n1);
    vector<int> R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
        shifts++; 
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
        shifts++; 
    }
    int i = 0; 
    int j = 0; 
    int k = left; 
    while (i < n1 && j < n2) {
        comparisons++; 
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        shifts++; 
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        shifts++; 
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        shifts++; 
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right, int& comparisons, int& shifts) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, comparisons, shifts);
        mergeSort(arr, mid + 1, right, comparisons, shifts);
        merge(arr, left, mid, right, comparisons, shifts);
    }
}

int main() {
    int t;
    cout << "Abhilakshya Bhatt\nRoll Number: 03\nUniversity Roll Number: 2023975\n";
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        int n;
        cout << "Enter the size of array: ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the elements of array: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int comparisons = 0, shifts = 0;
        mergeSort(arr, 0, n - 1, comparisons, shifts);
        cout << "Sorted array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\nTotal comparisons: " << comparisons <<"\nTotal shifts: " << shifts << endl;
    }
    return 0;
}