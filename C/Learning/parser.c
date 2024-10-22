/*To Prase and trim the given html string*/
#include <stdio.h>
#include <string.h>
void parser(char * string)
{
    int index=0,in=0,i;
    for(i=0;i<strlen(string);i++)
    {
        if(string[i]=='<')
        {
            in=1;
            continue;
        }
        else if (string[i]=='>')
        {
            in=0;
            continue;
        }
        if(in==0)
        {
            string[index]=string[i];
            index++;
        }
    }
    string[index]='\0';
}
void trim(char * string)
{
    int i;
    while(string[0]==' ')
    {
        for(i=0;i<strlen(string);i++)
        {
            string[i]=string[i+1];
        }
    }
    while(string[strlen(string)-1]==' ')
    {
        string[strlen(string)-1]='\0';
    }
}
void main()
{
    char string[]="<h1>      This is a Heading      <h2>";
    parser(string);
    printf("The Parsed String is :\n~~%s~~\n",string);
    trim(string);
    printf("The Trimmed String is :\n~~%s~~\n",string);
}