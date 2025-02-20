//WAP to find the indces of the two numbers such that they add up to a specific target number that is in the array itself. You may assume that each input would have exactly one solution, and you may not use the same element twice.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << "Enter the target sum: ";
    cin >> target;
    sort(arr.begin(), arr.end());
    int low = 0, high = n - 1;
    if(binary_search(arr.begin(), arr.end(), target)){
        while (low < high) {
            int sum = arr[low] + arr[high];
            if (sum == target) {
                cout << "Indices of the two numbers are: " << low << " and " << high << endl;
                return 0;
            } else if (sum < target) {
                ++low;
            } else {
                --high;
            }
        }
        cout << "No such pair found!" << endl;
    }
    else{
        cout << "Target sum not found in the array!" << endl;
    }

    return 0;
}