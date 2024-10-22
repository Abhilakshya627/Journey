/*To check a number for it to be palindrome or not*/
#include <stdio.h>
int isPalin(int number)
{
    int n1 = number, rev = 0;
    while (n1 > 0)
    {
        int d = n1 % 10;
        rev = rev * 10 + d;
        n1 = n1 / 10;
    }
    if (rev == number)
        return 1;
    else
        return 0;
}
void main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);
    if (isPalin(n))
    {
        printf("The number is a palindrome number");
    }
    else
    {
        printf("The number is not a palindrome number");
    }
}