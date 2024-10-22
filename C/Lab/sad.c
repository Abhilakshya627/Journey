#include <stdio.h>
void Sad(int a[][100],int r, int c)
{
    int i,j,p=0;
    for(i=0;i<r;i++)
    {
        int min=a[i][0];
        for(j=0;j<c;j++)
        {
            if(min>a[i][j])
            {
                min = a[i][j];
                p=j;
            }
        }
        int max=a[0][p];
        for(j=0;j<r;j++)
        {
            if(max<a[j][p] )
                max = a[j][p];
        }
        if(min==max)
        printf("%d, ",min);
    }
}
void main()
{
    int arr[100][100],row,col,i,j;
    printf("Enter number of rows : ");
    scanf("%d",&row);
    printf("Enter number of columns : ");
    scanf("%d",&col);
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("Enter element %d%d : ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\nThe matrix is :\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("The Seddle points are : ");
    Sad(arr,row,col);
}