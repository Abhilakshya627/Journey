//Given aan unsorted array of integers, design and implement it using a program to sort an array by partioning the array into two subarrays based on a pivot element such that one subarray holds values smaller than the pivot element while another subarray holds values greater than the pivot element. The process is repeated on the subarrays until the array is sorted. The pivot element should be selected at random. Your program should also find the number of comparisons and shifts made for sorting the array.
#include <bits/stdc++.h>
using namespace std;

int comparisons = 0;
int shifts = 0;

void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int partition(int array[], int low, int high) {
    srand(time(0));
    int pivotIndex = (rand() % (high - low + 1)) + low;
    swap(array, pivotIndex, high);
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (array[j] < pivot) {
            i++;
            swap(array, i, j);
            shifts += 2;
        }
    }
    swap(array, i + 1, high);
    shifts += 2;
    return i + 1;
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int array[] = {5, 2, 9, 1, 7, 3, 6, 8, 4};
    int size = sizeof(array) / sizeof(array[0]);
    quickSort(array, 0, size - 1);
    cout << "Sorted array: ";
    printArray(array, size);
    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of shifts: " << shifts << endl;
    return 0;
}