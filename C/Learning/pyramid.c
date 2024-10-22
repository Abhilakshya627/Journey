/*To print the following patttern :
   1
  222
 33333
4444444    (assuming n=4)
*/
#include <stdio.h>
void main()
{
    int n,i,j;
    printf("Enter Number of rows in Pyramid : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            printf("  ");
        }
        for(j=1;j<2*i;j++)
        {
            printf("%d ",i);
        }
        printf("\n");
    }
}