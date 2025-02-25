
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void removeDuplicates(vector<int>& arr, int& duplicateCount) {
    if (arr.empty()) return;

    int index = 1;
    duplicateCount = 0;

    for (int i = 1; i < arr.size(); ++i) {
        // Use binary search to check if the current element exists in the processed portion
        int pos = binarySearch(arr, 0, index - 1, arr[i]);
        if (pos == -1) {
            arr[index++] = arr[i];
        } else {
            ++duplicateCount;
        }
    }

    arr.resize(index);
}


int main() {
    vector<int> arr = {1, 1, 2, 2, 2, 3, 4, 4, 5};
    int duplicateCount = 0;

    removeDuplicates(arr, duplicateCount);

    cout << "Array after removing duplicates: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Number of duplicates removed: " << duplicateCount << endl;

    return 0;
}
