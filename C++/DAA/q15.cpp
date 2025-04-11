//Given two sorted arrays of integers of size m and n, design an algorithm and implement it using a program to find out list of elements which are common in both arrays. Time Complexity should be O(m+n).
#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cout << "Enter the size of first array: ";
    cin >> m;
    cout << "Enter the size of second array: ";
    cin >> n;
    vector<int> arr1(m), arr2(n);
    cout << "Enter elements of first array: ";
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }
    cout << "Enter elements of second array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }
    vector<int> commonElements;
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] == arr2[j]) {
            commonElements.push_back(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    cout << "Common elements: ";
    for (int elem : commonElements) {
        cout << elem << " ";
    }
    
    return 0;
}