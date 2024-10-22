/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.*/

#include<stdio.h>
#include<stdlib.h>
void sumtar(int *arr,int size,int target)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]+arr[j]==target)
            {
                printf("[%d,%d]\n",i,j);
                exit(0);
            }
        }
    }
}
void main()
{
    int n,tar;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
    printf("Enter elements :\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d : ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Enter target : ");
    scanf("%d",&tar);
    sumtar(a,n,tar);
}