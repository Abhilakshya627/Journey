// Given a sorted array of positive integers containing few duplicate elements, design an algorithm and implement it using a program to find whether the given key element is present in the array or not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))
#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(const vector<int>& arr, int key) {
    int left = 0, right = arr.size() - 1;
    int result = -1; 
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            result = mid; 
            right = mid - 1;
        } else if (arr[mid] < key) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return result;
}

int lastOccurrence(const vector<int>& arr, int key) {
    int left = 0, right = arr.size() - 1;
    int result = -1; 
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            result = mid; 
            left = mid + 1; 
        } else if (arr[mid] < key) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return result;
}

int main() {
    int t; 
    cout << "Abhilakshya Bhatt\nRoll Number: 03\nUniversity Roll Number: 2023975\n";
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        int n; 
        cout<<"Enter the size of array: ";
        cin >> n;
        vector<int> arr(n);
        cout<<"Enter the elements of array: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; 
        }
        int key;
        cout<<"Enter the key element: "; 
        cin >> key;
        int firstIndex = firstOccurrence(arr, key);
        if (firstIndex == -1) {
            cout << "Key not present" << endl; 
        } else {
            int lastIndex = lastOccurrence(arr, key);
            int count = lastIndex - firstIndex + 1;
            cout <<"Key found.\nNumber of Occurances of key in array : "<< count << endl; 
        }
    }

    return 0;
}