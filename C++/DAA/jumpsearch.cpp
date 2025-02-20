#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int jumpSearch(const vector<int>& arr, int x) {
    int n = arr.size();
    int jump = sqrt(n); 
    int prev = 0;
    while (arr[min(jump, n) - 1] < x) {
        prev = jump;
        jump += sqrt(n);
        if (prev >= n) {
            return -1; 
        }
    }
    //linearSearch
    /*for (int i = prev; i < min(jump, n); i++) {
        if (arr[i] == x) {
            return i; 
        }
    }*/

    //BinarySearch
    int low = prev, high = min(jump, n) - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n, x;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the element to be searched: ";
    cin >> x;
    sort(arr.begin(), arr.end());
    int result = jumpSearch(arr, x);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}