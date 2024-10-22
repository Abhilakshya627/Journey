#include <stdio.h>
int m(int a[][100], int r, int c)
{
    int max = a[0][0], i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (max < a[i][j])
                max = a[i][j];
        }
    }
    return max;
}
void main()
{
    int a[100][100], i, j, r, c, sum;
    printf("Enter number of rows : ");
    scanf("%d", &r);
    printf("Enter number of column : ");
    scanf("%d", &c);
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("Enter element %d%d : ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nThe matrix is :\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    int l = m(a, r, c);
    printf("The largest element of the array is %d", l);
}