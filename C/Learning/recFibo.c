/*To Print fibonacci series upto n terms*/
#include <stdio.h>
int fibo(int n, int a, int b)
{
    if (n == 0)
    {
        printf("0 = ");
        return 0;
    }
    else
    {
        printf("%d + ", a);
        return a + fibo(n - 1, b, a + b);
    }
}
void main()
{
    int n;
    printf("Enter number of terms in fibonacci series : ");
    scanf("%d", &n);
    printf("The series till nth term is :\n");
    printf("%d", fibo(n, 0, 1));
}