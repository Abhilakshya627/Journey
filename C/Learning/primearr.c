#include <stdio.h>
void input(int a[],int n)
{
    printf("Enter elements of the array : \n");
    for(int i=0;i<n;i++)
    {
        printf("Enter %d element : ",i+1);
        scanf("%d",&a[i]);
    }
    printf("\n");
}
void print(int a[],int n)
{
    printf("The array is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d, ",a[i]);
    }
    printf("\n");
}
int isprime(int n)
{
    int c=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        c++;
    }
    printf("\n");
    if(c==2)
    return 1;
    else 
    return 0;
}
int cprime(int a[],int n)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(isprime(a[i]))
        c++;
    }
    printf("\n");
    return c;
}
void main()
{
    int n;
    printf("Enter Length of array : ");
    scanf("%d",&n);
    int a[n];
    input(a,n);
    print(a,n);
    printf("There are %d prime numbers in the array.\n",cprime(a,n));
}