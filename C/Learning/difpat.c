/*
4444444
4333334
4322234
4321234
4322234
4333334
4444444
*/
#include<stdio.h>
void main()
{
    int n,i,j;
    printf("Enter a number : ");
    scanf("%d",&n);
    for(i=n;i>=1;i--)
    {
        for(j=n;j>=i;j--)
        {
            printf("%d ",j);
        }
        for(j=i;j>1;j--)
        {
            if(j!=1)
            printf("%d ",i);
        }
        for(j=i;j>=1;j--)
        {
            if(j!=1)
            printf("%d ",i);
        }
        for(j=i+1;j<=n;j++)
        {
            printf("%d ",j);
        }
        printf("\n");
    }
    for(i=0;i<n-1;i++)
    {
        for(j=n;j>2+i;j--)
        {
            printf("%d ",j);
        }
        for(j=1;j<=2+i;j++)
        {
            printf("%d ",2+i);
        }
        for(j=1;j<=2+i-1;j++)
        {
            printf("%d ",2+i);
        }
        for(j=2+i+1;j<=n;j++)
        {
            printf("%d ",j);
        }
        printf("\n");
    } 
}