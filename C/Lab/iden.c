#include <stdio.h>
void main()
{
    int a[100][100], b[100][100], ra, ca, rb, cb, i, j;
    printf("Enter number of rows of matrix A : ");
    scanf("%d", &ra);
    printf("Enter number of column of matrix A : ");
    scanf("%d", &ca);
    printf("Enter number of rows of matrix B : ");
    scanf("%d", &rb);
    printf("Enter number of column of matrix B : ");
    scanf("%d", &cb);
    if (ra == rb && ca == cb)
    {
        printf("Enter elements of the matrix A :\n");
        for (i = 0; i < ra; i++)
        {
            for (j = 0; j < ca; j++)
            {
                printf("Enter element %d%d : ", i + 1, j + 1);
                scanf("%d", &a[i][j]);
            }
        }
        printf("Enter elements of the matrix B :\n");
        for (i = 0; i < rb; i++)
        {
            for (j = 0; j < cb; j++)
            {
                printf("Enter element %d%d : ", i + 1, j + 1);
                scanf("%d", &b[i][j]);
            }
        }
        int f=0;
        for (i = 0; i < rb; i++)
        {
            for (j = 0; j < cb; j++)
            {
                if(a[i][j]!=b[i][j])
                {
                    f++;
                    break;
                }                
            }
        }
        if(f==0)
        {
            printf("The matrices are identical\n");
        }
        else 
        {
            printf("The matrices are not identical\n");
        }
    }
    else
    {
        printf("Since the number of rows and columns is not equal the matrices cannot be identical\n");
    }
}