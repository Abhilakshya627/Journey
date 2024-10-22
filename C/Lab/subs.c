#include <string.h>
#include <stdio.h>
void addsp(char *s)
{
    int p, l = strlen(s);
    printf("Enter position where you want to add new string (Position starts from 1): ");
    scanf("%d", &p);
    getchar();
    if (p < 1 || p > l + 1)
    {
        printf("\nInvalid Position\n");
        return;
    }
    else
    {
        char s1[100];
        printf("Enter String : ");
        gets(s1);
        int sl=strlen(s1);
        if(l+sl-1>=100)
        {
            printf("\nString too long.\n");
            return ;
        }
        else
        {
            int i=0;
            for(i=l;i>=p;i--)
            {
                s[i+sl] = s[i];
            }
            for(i=0;i<sl;i++)
            {
                s[p+i]=s1[i];
            }
            s[l + sl]='\0';
        }
    }
}
void main()
{
    char s[100], *p = s;
    printf("Enter a string : ");
    gets(s);
    addsp(p);
    puts(s);
}