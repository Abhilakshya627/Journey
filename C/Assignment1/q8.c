#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to remove duplicates from a sorted array and return the new size
int removeDuplicates(int* arr, int size) {
    if (size == 0) return 0;

    int uniqueIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[uniqueIndex]) {
            uniqueIndex++;
            arr[uniqueIndex] = arr[i];
        }
    }
    return uniqueIndex + 1;
}

// Function to find the union and intersection of arrays A and B
void findUnionIntersection(int* A, int* B, int size) {
    // Sort both arrays
    bubbleSort(A, size);
    bubbleSort(B, size);

    // Remove duplicates from both arrays
    int newSizeA = removeDuplicates(A, size);
    int newSizeB = removeDuplicates(B, size);

    // Find union and store in A
    int unionIndex = newSizeA;
    for (int i = 0; i < newSizeB; i++) {
        int isInA = 0;
        for (int j = 0; j < newSizeA; j++) {
            if (B[i] == A[j]) {
                isInA = 1;
                break;
            }
        }
        if (!isInA) {
            A[unionIndex++] = B[i];
        }
    }

    // Remove duplicates again from A (union array)
    unionIndex = removeDuplicates(A, unionIndex);

    // Find intersection and store in B
    int intersectionIndex = 0;
    for (int i = 0; i < newSizeB; i++) {
        for (int j = 0; j < newSizeA; j++) {
            if (B[i] == A[j]) {
                B[intersectionIndex++] = B[i];
                break;
            }
        }
    }
    bubbleSort(A,unionIndex);

    // Print the union
    printf("Union of arrays: ");
    for (int i = 0; i < unionIndex; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Print the intersection
    printf("Intersection of arrays: ");
    for (int i = 0; i < intersectionIndex; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");
}


void main(){
    int n,i,j,*a,*b,f,c=0,d;
    printf("Enter sizes of array A and B : ");
    scanf("%d",&n);
    a=(int*)malloc(2*n*sizeof(int));
    b=(int*)malloc(n*sizeof(int));
    printf("Enter elements of array A :\n");
    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",a+i);
    }
    printf("Enter elements of array B :\n");
    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",b+i);
    }
    findUnionIntersection(a,b,n);
    free(a);
    free(b);
}