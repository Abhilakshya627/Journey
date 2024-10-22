/*Using dynamic memory allocation input empoly id of n employees*/
#include <stdio.h>
#include <stdlib.h>
void main()
{
    int ne,n;
    char *id ;
    printf("Enter number of employee Entries you want to do : ");
    scanf("%d",&ne);
    printf("\n");
    printf("\n");
    while(ne>0)
    {
        printf("Enter number of characters in Employee ID : ");
        scanf("%d",&n);
        id= (char *)malloc((n+1)*sizeof(char));
        printf("Enter Employee ID : ");
        scanf("%s",id);
        printf("The Employee ID is : %s\n",id);
        printf("\n");
        ne--;
    }
}