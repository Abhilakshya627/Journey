
//Given an unsorted array of integers, design & implement a program to sort an array by dividing the array into subarrays and then comparing the subarrays and insert them in position to get the sorted array. Your program should also find the number of comparisons and shifts required for sorting the array.
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& a, int left, int mid, int right, int& comparisons, int& shifts) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);
    for (int i = 0; i < n1; i++) {
        leftArr[i] = a[left + i];
        shifts++; // Counting shifts 
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = a[mid + 1 + j];
        shifts++; // Counting shifts
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparisons++; // Counting comparisons
        if (leftArr[i] <= rightArr[j]) {
            a[k] = leftArr[i];
            i++;
        } else {
            a[k] = rightArr[j];
            j++;
        }
        k++;
        shifts++; // Counting shifts
    }
    while (i < n1) {
        a[k] = leftArr[i];
        i++;
        k++;
        shifts++; // Counting shifts
    }
    while (j < n2) {
        a[k] = rightArr[j];
        j++;
        k++;
        shifts++; // Counting shifts
    }
}

void mergeSort(vector<int>& a, int left, int right, int& comparisons, int& shifts) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid, comparisons, shifts);
        mergeSort(a, mid + 1, right, comparisons, shifts);
        merge(a, left, mid, right, comparisons, shifts);
    }
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int comparisons = 0, shifts = 0;
        mergeSort(arr, 0, n - 1, comparisons, shifts);
        cout << "Array after sorting: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "Number of comparisons: " << comparisons << endl;
        cout << "Number of shifts: " << shifts << endl;
        cout << endl;
    }

    return 0;
}