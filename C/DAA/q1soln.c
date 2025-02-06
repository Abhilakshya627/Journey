#include <stdio.h>
#include <stdlib.h>

void sortColors(int* nums, int numsSize) {
    int low = 0, mid = 0, high = numsSize - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            // Swap nums[low] and nums[mid]
            int temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else { // nums[mid] == 2
            // Swap nums[mid] and nums[high]
            int temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;
            high--;
        }
    }
}
int main(){
    int n,i;
    printf("Enter size of array : ");
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    printf("Enter elements of array\n");
    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Printing array : ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    sortColors(a,n);
    printf("\nPrinting sorted array : ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}