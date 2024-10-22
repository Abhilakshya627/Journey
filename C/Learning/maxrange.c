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
int max(int a[],int n,int p,int q)
{
    int max=a[p];
    for(int i=p;i<q;i++)
    {
        if(max<a[i])
        max=a[i];
    }
    return max;
}
void main()
{
    int n,p,q;
    printf("Enter Length of array : ");
    scanf("%d",&n);
    int a[n];
    input(a,n);
    printf("Note : In array index starts from 0.\n");
    printf("Enter index from where you want to start : ");
    scanf("%d",&p);
    printf("Enter index where you want to end : ");
    scanf("%d",&q);
    print(a,n);
    if(p>=0 || q<n || p<=q)
    printf("The maximum in the range between index %d to %d is : %d",p,q,max(a,n,p,q));
    else 
    printf("Out of range of the array !!!\n");
}