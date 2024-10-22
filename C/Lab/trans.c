#include <stdio.h>
void main()
{
    int a[100][100], b[100][100], r, c, i, j;
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
            b[j][i] = a[i][j];
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
    printf("\nThe transpose matrix is :\n");
    for (i = 0; i < c; i++)
    {
        for (j = 0; j < r; j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
}