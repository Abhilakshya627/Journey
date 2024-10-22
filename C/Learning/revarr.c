/*To input and reverse an array*/
#include <stdio.h>
void rev(int arr[], int n)
{
    int i;
    for (i = 0; i < n ; i++)
    {
       int x=arr[i],s=0;
       while(x>=0)
       {
        s+=(x%10);
        x=x/10;
       }
       arr[i]=s;
    }
}
void printarr(int arr[], int n)
{
    int i;
    printf("The array is as follows : ");
    for (i = 0; i < n - 1; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("%d\n", arr[n - 1]);
}
void main()
{
    int n, i, temp;
    printf("Enter length of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of array : \n");
    for (i = 0; i < n; i++)
    {
        printf("Enter %d element : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printarr(arr, n);
    rev(arr, n);
    printf("Reversed Array : \n");
    printarr(arr, n);
}