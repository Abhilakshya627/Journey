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
void rev(int arr[], int n)
{
    int temp, i;
    for (i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}
void main()
{
    int n,p;
    printf("Enter Length of array : ");
    scanf("%d",&n);
    int a[n];
    input(a,n);
    print(a,n);
    printf("Note : In array index starts from 0.\n");
    printf("Enter index till you want to reverse : ");
    scanf("%d",&p);
    if(p<=n)
    {
        rev(a,p);
        print(a,n);
    }
    else
    {
        printf("Out of bounds!!\n");
    }
}