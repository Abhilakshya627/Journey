/*Write a code to create a structure for book data with fields publisher, book name, cost
and no of copies. Store 50 records and print the count of all the books published by the
publisher “Oxford”*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct book
{
    char name[50];
    char publisher[50];
    int cost;
    int copies;
}bo;

void main()
{
    int i=0;
    bo b[50];
    printf("Enter details of the books:\n");
    for(i=0;i<50;i++)
    {
        printf("Enter book name : ");
        gets(b[i].name);
        getchar();
        printf("Enter publisher name : ");
        gets(b[i].publisher);
        printf("Enter cost : ");
        scanf("%d",&b[i].cost);
        printf("Enter no. of copies : ");
        scanf("%d",&b[i].copies);
        getchar();
    }
    printf("Books of publisher 'Oxford':\n");
    for(i=0;i<50;i++)
    {
        if(strcmp(b[i].publisher,"Oxford")==0)
        {
            printf("Book name : %s\n",b[i].name);
            printf("No. of copies : %d\n\n",b[i].copies);
        }
    }
}
