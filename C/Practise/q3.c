#include <stdio.h>

struct stud
{
    char name[100];
    int rno;
    char sec;
    int m1;
    int m2;
    int m3;
};

void main()
{
    int i;
    struct stud s[5];
    FILE *p=fopen("DATA.txt","w");
    if(p==NULL)
    {
        printf("Error in opening file.\n");
       
    }
    else
    {
        printf("Enter customer info:\n");
        for(i=0;i<5;i++)
        {
            printf("Enter details of Student %d:\n",i+1);
            printf("Name : ");
            gets(s[i].name);
            printf("Roll number : ");
            scanf("%d",&s[i].rno);
            getchar();
            printf("Section : ");
            scanf("%c",&s[i].sec);
            printf("Marks in Subject 1 : ");
            scanf("%d",s[i].m1);
            printf("Marks in Subject 2 : ");
            scanf("%d",s[i].m2);
            printf("Marks in Subject 3 : ");
            scanf("%d",s[i].m3);
            getchar();
        }
        for(i=0;i<5;i++)
        {
            
            fprintf(p,"%s\n",s[i].name);
            fprintf(p,"%d\n",s[i].rno);
            fprintf(p,"%c\n",s[i].sec);
            fprintf(p,"%d\n",s[i].m1);
            fprintf(p,"%d\n",s[i].m2);
            fprintf(p,"%d\n",s[i].m3);
        }
        fclose(p);
    }
}