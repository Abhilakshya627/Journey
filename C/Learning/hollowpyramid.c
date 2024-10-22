/*To print the following pattern :
    *
   * *
  *   *                 (assuming n=5)
 *     *
* * * * *
*/
#include <stdio.h>
void main()
{
    int n,i,j;
    printf("Enter Number of rows in Pyramid : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=i;j<n;j++)
        {
            printf("  ");   
        }
        for(j=1;j<=2*i-1;j++)
        {
            if(j==1 || j==2*i-1 || i==n)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    for(i=1;i<=n+(n-1);i++)
    {
        printf("* ");
    }
}