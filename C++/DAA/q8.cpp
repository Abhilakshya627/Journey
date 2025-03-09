 #include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right,int comparisons,int shifts) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
        shifts++;
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
        shifts++;
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        shifts++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        shifts++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        shifts++;
    }
}

void mergeSort(vector<int>& arr, int left, int right,int comparisons,int shifts) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid,comparisons,shifts);
        mergeSort(arr, mid + 1, right,comparisons,shifts);
        merge(arr, left, mid, right,comparisons,shifts);
    }
}

vector<int> removeDuplicates(vector<int>& arr) {
    set<int> uniqueElements(arr.begin(), arr.end());
    return vector<int>(uniqueElements.begin(), uniqueElements.end());
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;
        vector<int> arr (n);
        int comparisons = 0, shifts = 0;
        mergeSort(arr, 0, arr.size() - 1, comparisons, shifts);
        vector<int> uniqueArr = removeDuplicates(arr);
        cout << "Sorted array without duplicates: ";
        for (int num : uniqueArr) {
            cout << num << " ";
        }
        cout << endl;
        cout << "Number of comparisons: " << comparisons << endl;
        cout << "Number of shifts: " << shifts << endl;
    }
    
    return 0;
}