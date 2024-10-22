//WAP to pass array to a function and sort the elements of the array in ascending order.
#include <stdio.h>
void input(int a[],int n)
{
    int i;
    printf("Enter elements of the array\n");
    for(i=0;i<n;i++)
    {
        printf("Enter element %d : ",i+1);
        scanf("%d",&a[i]);
    }
    printf("\n");
}
void print(int a[],int n)
{
    int i;
    printf("The array is : ");
    for(i=0;i<n;i++)
    {
        printf("%d, ",a[i]);
    }
    printf("\n");
}
void sort(int a[],int n)
{
    int i,j,t;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
}
void main()
{
    int a[100],n;
    printf("Enter length of the array : ");
    scanf("%d",&n);
    input(a,n);
    print(a,n);
    sort(a,n);
    printf("After sorting : \n");
    print(a,n);
}