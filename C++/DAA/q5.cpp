//Given a sorted array of positive integers, design an algorithm and implement it using a program to find three indices i, j, k such that arr[i] + arr[j] = arr[k].
#include <bits/stdc++.h>
using namespace std;

void findIndices(const vector<int>& arr) {
    int n = arr.size();
    bool found = false;
    for (int k = 2; k < n; k++) {
        int i = 0; 
        int j = k - 1; 

        while (i < j) {
            int sum = arr[i] + arr[j];
            if (sum == arr[k]) {
                cout << "Found indices: i = " << i << ", j = " << j << ", k = " << k << endl;
                cout << "Values: arr[i] = " << arr[i] << ", arr[j] = " << arr[j] << ", arr[k] = " << arr[k] << endl;
                found = true;
                break; 
            } else if (sum < arr[k]) {
                i++; 
            } else {
                j--; 
            }
        }
    }
    if (!found) {
        cout << "No sequence found." << endl;
    }
}

int main(){
    int t;
    cout << "Abhilakshya Bhatt\nRoll Number: 03\nUniversity Roll Number: 2023975\n";
    cout << "Enter the number of test cases: ";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter the size of array: ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the elements of array: ";
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        findIndices(arr);
    }

    return 0;
}