/*To print the following pattern :
 *      *
 **    **
 ***  ***
 ********
 */
#include <stdio.h>
void main()
{
    int n, i, j;
    printf("Enter number of rows : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++) // Loop for 1st Star Pattern
        {
            printf("* ");
        }
        for (j = (n - i) * 2; j >= 0; j--) // Loop for printing spaces
        {
            printf("  ");
        }
        for (j = 1; j <= i; j++) // Loop for 2nd Star Pattern
        {
            printf("* ");
        }
        printf("\n");
    }
}