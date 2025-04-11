//Given an unsorted array of integers, design an algorithm and implement it using a program to find out whether their exists a pair of elements whose sum is equal to the given number. Time Complexity should be O(nlogn).
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int target;
    cout << "Enter the target sum: ";
    cin >> target;
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum == target){
            cout << "Pair found: " << arr[left] << ", " << arr[right] << endl;
            break;
        }
        else if(sum < target){
            left++;
        }
        else{
            right--;
        }
    }   
    if(left >= right){
        cout << "No pair found with the given sum." << endl;
    }

    return 0;
}