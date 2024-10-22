#include <stdio.h>
int dup(int arr[],int n)
{
    int i,j,c=0;
    printf("The duplicates are : ");
    for(i=0;i<n;i++)
    {
        int ci=0;
        for(j=i+1;j<n-c;j++)
        {
            if(arr[i]==arr[j])
            {
                ci++;
                c++;
                if(ci<=1)
                printf("%d, ",arr[j]);
                for(int k=j;k<n-1;k++)
                {
                    int t=arr[k];
                    arr[k]=arr[k+1];
                    arr[k+1]=t;
                }
            }
        }
    }
    return c;
}
void print(int a[],int n)
{
    printf("\nThe Array : ");
    for(int i=0;i<n-1;i++)
    {
        printf("%d, ",a[i]);
    }
    printf("%d",a[n-1]);
}
void main()
{
    int i,n,c;
    printf("Enter length of array : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements of the Array -\n");
    for(i=0;i<n;i++)
    {
        printf("Enter element %d : ",i+1);
        scanf("%d",&a[i]);
    }
    c=dup(a,n);
    print(a,n-c);
}