/*To print Multiplication table of the number entered by the user*/
#include <stdio.h>
void main()
{
    int n, i;
    printf("Enter number whose Multiplication table you want : ");
    scanf("%d", &n);
    printf("Table of %d :\n", n);
    for (i = 1; i <= 10; i++)
    {
        printf("%d X %d = %d \n", n, i, n * i);
    }
}