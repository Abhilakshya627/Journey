// Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether a given key element is present in the sorted array or not. For an array arr[n], search at the indexes arr[0], arr[2], arr[4],...,arr[2k] and so on. Once the interval (arr[2k] < key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k to find the element key. (Complexity <O(n), where n is the number of elements need to be scanned for searching)
#include <bits/stdc++.h>
using namespace std;

int jumpSearch(const vector<int>& arr, int n, int key, int &comparisons) {
    int step = sqrt(n); 
    int prev = 0;
    comparisons = 0;
    while (arr[min(step, n) - 1] < key) {
        comparisons++;
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }
    while (prev < min(step, n)) {
        comparisons++;
        if (arr[prev] == key) {
            return prev; 
        }
        prev++;
    }
    return -1; 
}

int main() {
    int t;
    cout << "Abhilakshya Bhatt\nRoll Number: 03\nUniversity Roll Number: 2023975\n";
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        int n;
        cout << "Enter the number of elements in the array: ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int key;
        cout << "Enter the element to be searched: ";
        cin >> key;
        int comparisons = 0; 
        int result = jumpSearch(arr, n, key, comparisons);
        if (result != -1) {
            cout << "Element found at index: " << result << endl;
        } else {
            cout << "Element not found in the array." << endl;
        }
        cout << "Number of comparisons made: " << comparisons << endl; 
    }
    return 0;
}