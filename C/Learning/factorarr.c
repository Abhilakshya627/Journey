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
void fac(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\nThe factors of %d are : ",a[i]);
        for(int j=1;j<=a[i];j++)
        {
            if(a[i]%j==0)
            printf("%d, ",j);
        }
        printf("\n");
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
    fac(a,n);
}