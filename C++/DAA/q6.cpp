//Given an array of nonnegative integers, design an algorithm and a program to count the number of pairs of integers such that their difference is equal to a given key, K.
#include <bits/stdc++.h>
using namespace std;

int countPairsWithDifference(const vector<int>& arr, int K) {
    unordered_set<int> seen; 
    int count = 0; 
    for (int x : arr) {
        if (seen.find(x + K) != seen.end()) {
            count++;
        }
        if (seen.find(x - K) != seen.end()) {
            count++;
        }
        seen.insert(x);
    }

    return count;
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
        int k;
        cout << "Enter the value of K: ";
        cin >> k;
        cout << "Number of pairs with difference " << k << ": " << countPairsWithDifference(arr, k) << endl;
    }
    
    return 0;
}