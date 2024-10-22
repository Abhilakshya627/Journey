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
int fact(int n)
{
    int f=1;
    while (n>=1)
    {
        f*=n;
        n--;
    }
    return f;
}
void rep(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        a[i]=fact(a[i]);
    }
}
void main()
{
    int n;
    printf("Enter Length of array : ");
    scanf("%d",&n);
    int a[n];
    input(a,n);
    print(a,n);
    rep(a,n);
    print(a,n);
}