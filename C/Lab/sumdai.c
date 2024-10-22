#include <stdio.h>
void main()
{
    int n,a[100][100],s=0;
    printf("Enter Number of rows and columns : ");
    scanf("%d",&n);
    int i,j;
    printf("Enter elements of the array :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter element %d%d : ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    printf("The array is :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
            if(i==j || (i+j)==(n-1))
            s+=a[i][j];   
        }
        printf("\n");
    }
    printf("Sum of diagonal elements is : %d\n",s);
}