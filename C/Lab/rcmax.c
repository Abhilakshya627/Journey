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
    for (i = 0; i < r; i++)
    {
        int max=a[i][0];
        for (j = 1; j < c; j++)
        {
            if(max<a[i][j])
            max=a[i][j];
        }
        printf("Max of row %d is %d\n",i+1,max);
    }
    for (i = 0; i < c; i++)
    {
        int max=a[0][i];
        for (j = 1; j < r; j++)
        {
            if(max<a[j][i])
            max=a[j][i];
        }
        printf("Max of column %d is %d\n",i+1,max);
    }
}