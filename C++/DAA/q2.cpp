//Write a program to implement linear search, binary search and jump search and count the number of comparisons in each case.
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void linearSearch(const std::vector<int>& a, int key) {
    int n = a.size();
    int count = 0;
    std::cout << "Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++) {
        ++count;
        if (a[i] == key) {
            cout << "Element found at index: " << i << endl;
            cout << "Number of comparisons: " << count << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
    cout << "Number of comparisons: " << count << endl;
}

void binarySearch(const vector<int>& a, int key) {
    int n = a.size();
    int count = 0;
    vector<int> sortedArray = a; // Create a copy of the array and sort it
    sort(sortedArray.begin(), sortedArray.end());
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << sortedArray[i] << " ";
    }
    cout << endl;

    int low = 0, high = n - 1;
    while (low <= high) {
        ++count;
        int mid = low + (high - low) / 2;
        if (sortedArray[mid] == key) {
            cout << "Element found at index: " << mid << " (in sorted array)" << endl;
            cout << "Number of comparisons: " << count << endl;
            return;
        } else if (sortedArray[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Element not found" << endl;
    cout << "Number of comparisons: " << count << endl;
}

void jumpSearch(const vector<int>& a, int key) {
    int n = a.size();
    int count = 0;
    int step = static_cast<int>(sqrt(n));
    int prev = 0;
    vector<int> sortedArray = a; // Create a copy of the array and sort it
    sort(sortedArray.begin(), sortedArray.end());
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << sortedArray[i] << " ";
    }
    cout << endl;

    while (sortedArray[min(step, n) - 1] < key) {
        ++count;
        prev = step;
        step += static_cast<int>(sqrt(n));
        if (prev >= n) {
            cout << "Element not found" << endl;
            cout << "Number of comparisons: " << count << endl;
            return;
        }
    }

    while (sortedArray[prev] < key) {
        ++count;
        prev++;
        if (prev == min(step, n)) {
            cout << "Element not found" << endl;
            cout << "Number of comparisons: " << count << endl;
            return;
        }
    }

    if (sortedArray[prev] == key) {
        cout << "Element found at index: " << prev << " (in sorted array)" << endl;
        cout << "Number of comparisons: " << count << endl;
        return;
    }
    cout << "Element not found" << endl;
    cout << "Number of comparisons: " << count << endl;
}

int main() {
    int n, key;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Enter the key: ";
    cin >> key;
    cout << "Linear Search: " << endl;
    linearSearch(a, key);
    cout << endl << "Binary Search: " << endl;
    binarySearch(a, key);
    cout << endl << "Jump Search: " << endl;
    jumpSearch(a, key);

    return 0;
}