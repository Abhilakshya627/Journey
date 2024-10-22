#include <stdio.h>
struct Date
{
    int d;
    int m;
    int y;
};
typedef struct 
{
    char name[20];
    int roll;
    struct Date dob;
    struct Date doa;
}stud;
void main()
{
    int n,i;
    printf("Enter number of students : ");
    scanf("%d",&n);
    getchar();
    stud s[n];
    printf("Enter details of the students\n");
    for(i=0;i<n;i++)
    {
        printf("Enter details of %d student\n",i+1);
        printf("Name : ");
        gets(s[i].name);
        printf("Roll No. : ");
        scanf("%d",&s[i].roll);
        printf("Enter Date of Birth\n");
        printf("Date : ");
        scanf("%d",&s[i].dob.d);
        printf("Month : ");
        scanf("%d",&s[i].dob.m);
        printf("Year : ");
        scanf("%d",&s[i].dob.y);
        printf("Enter Date of Admission\n");
        printf("Date : ");
        scanf("%d",&s[i].doa.d);
        printf("Month : ");
        scanf("%d",&s[i].doa.m);
        printf("Year : ");
        scanf("%d",&s[i].doa.y);
        getchar();
    }
    printf("S.No\tRoll No.\tD.O.B\t\tD.O.A\t\t\tName\n");
    for(i=0;i<n;i++)
    {
        printf("%d.\t",i+1);
        printf("%d\t\t",s[i].roll);
        printf("%d/%d/%d\t\t",s[i].dob.d,s[i].dob.m,s[i].dob.y);
        printf("%d/%d/%d\t\t",s[i].doa.d,s[i].doa.m,s[i].doa.y);
        printf("%s\n",s[i].name);
    }
}