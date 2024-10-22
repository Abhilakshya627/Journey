#include <stdio.h>
#include <string.h>
void rev(char *s)
{
    int i, start, end, len = strlen(s);
    for (start = 0, end = len - 1; start < end; start++, end--)
    {
        char t = s[start];
        s[start] = s[end];
        s[end] = t;
    }

    start = 0;
    for (i = 0; i <= len; i++)
    {
        if (s[i] == ' ' || s[i] == '\0')
        {
            end = i - 1;
            while (start < end)
            {
                char t = s[start];
                s[start] = s[end];
                s[end] = t;
                start++;
                end--;
            }
            start = i + 1;
        }
    }
}
void main()
{
    char s[100],s1[100],*p=s;
    printf("Enter a string : ");
    gets(s);
    printf("Original String : ");
    puts(s);
    rev(p);
    printf("New String : ");
    puts(s);
}