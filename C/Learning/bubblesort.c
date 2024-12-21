#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int n, i, j, temp;
    int *a;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("Original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    // Bubble sort
    for(i=0;i<n-1;i++){
        bool swapped = false;
        for(j=0;j<n-i-1;j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped) break;
    }
    printf("\nSorted array: ");
    for(i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf('\n');
    free(a);

    return 0;

}