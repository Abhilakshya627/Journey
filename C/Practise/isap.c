#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of terms in series: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Not enough terms to determine if it's an arithmetic progression series\n");
        return 0;
    }

    int *a = (int*)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter %dth term: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("Given Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    int d = a[1] - a[0];
    int isAP = 1;

    for (int i = 1; i < n - 1; i++) {
        if (a[i + 1] - a[i] != d) {
            printf("Not an arithmetic progression series\n");
            isAP = 0;
            break;
        }
    }

    if (isAP) {
        printf("Arithmetic progression series\n");
    }

    free(a);
    return 0;
}
