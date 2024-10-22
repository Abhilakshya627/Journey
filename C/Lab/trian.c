#include <stdio.h>
void main()
{
    int r, c, a[100][100], i, j;
    printf("Enter Number of rows : ");
    scanf("%d", &r);
    printf("Enter Number of column : ");
    scanf("%d", &c);
    if (r == c)
    {
        printf("Enter elements of the array :");
        for (i = 0; i < r; i++)
         {
            for (j = 0; j < c; j++)
            {
                printf("\nEnter Element %d%d : ", i + 1, j + 1);
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
        int ut = 0, lt = 0;
        for (i = 1; i < r; i++)
        {
            for (j = 0; j < i; j++)
            {
                if (a[i][j] != 0)
                {
                    ut++;
                    break;
                }
            }
        }
        for (i = 0; i < r; i++)
        {
            for (j = i + 1; j < c; j++)
            {
                if (a[i][j] != 0)
                {
                    lt++;
                    break;
                }
            }
        }
        if(ut==0)
        {
            printf("The matrix is upper triangular matrix\n");
        }
        else if(lt==0)
        {
            printf("The matrix is lower triangular matrix\n");
        }
        else
        {
            printf("The matrix is neither upper triangular nor lower triangular\n");
        }
    }
    else
    {
        printf("The Matrix is not a square matrix hence it can be neither upper triangular nor lower triangular\n");
    }
}