#include <stdio.h>
#include <stdlib.h>

// Function to print an array
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int* a = (int*)malloc(n * sizeof(int));
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    int negativeCount = 0;
    int zeroCount = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            negativeCount++;
        } else if (a[i] == 0) {
            zeroCount++;
        }
    }

    int* negativeArray = (int*)malloc(negativeCount * sizeof(int));
    int* zeroArray = (int*)malloc(zeroCount * sizeof(int));
    int* positiveArray = (int*)malloc((n - negativeCount - zeroCount) * sizeof(int));

    int negativeIndex = 0;
    int zeroIndex = 0;
    int positiveIndex = 0;

    // Separate negative, zero, and positive numbers
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            negativeArray[negativeIndex++] = a[i];
        } else if (a[i] == 0) {
            zeroArray[zeroIndex++] = a[i];
        } else {
            positiveArray[positiveIndex++] = a[i];
        }
    }

    printf("The Rearranged Array is: ");
    printArray(negativeArray, negativeCount);
    printArray(zeroArray, zeroCount);
    printArray(positiveArray, n - negativeCount - zeroCount);

    printf("Negative Array: ");
    printArray(negativeArray, negativeCount);

    printf("Zero Array: ");
    printArray(zeroArray, zeroCount);

    printf("Positive Array: ");
    printArray(positiveArray, n - negativeCount - zeroCount);

    free(a);
    free(negativeArray);
    free(zeroArray);
    free(positiveArray);

    return 0;
}