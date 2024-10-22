/*To print the following pattern:
        1
        22
        333
        4444
        55555           (assuming n=5)
        4444
        333
        22
        1
*/
#include <stdio.h>
void main()
{
    int n,i,j;
    printf("Enter number of columns : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d ",i);
        }
        printf("\n");
    }
    for(i=n-1;i>0;i--) 
    {
        for(j=i;j>0;j--)
        {
            printf("%d ",i);
        }
        printf("\n");
    }
}