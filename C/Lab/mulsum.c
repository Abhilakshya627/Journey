#include <stdio.h>
int isMuld(int n)
{
    if ((n / 10) > 0)
        return 1;
    else
        return 0;
}
int s(int a[][100], int r, int c)
{
    int i, j, x, s = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            x = a[i][j];
            if (isMuld(x))
                s += x;
        }
    }
    return s;
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
    sum = s(a, r, c);
    printf("The sum of the multidigit elements of the array is %d\n", sum);
}