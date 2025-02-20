
#include <iostream>
#include <vector>
using namespace std;

void removeDuplicates(vector<int>& arr, int& duplicateCount) {
    if (arr.empty()) return;

    int index = 1;
    duplicateCount = 0;

    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] != arr[i - 1]) {
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