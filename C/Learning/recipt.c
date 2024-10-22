#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *replaceWord(const char *str, const char *oldWord, const char *newWord)
{
    char *resultString;
    int i, count = 0,c=1;
    int newWordLength = strlen(newWord);
    int oldWordLength = strlen(oldWord);
    for (i = 0; str[i] != '\0'; i++)
    { //Traverse the whole string and search for oldword
        if (strstr(&str[i], oldWord) == &str[i])
        { //Finds the number of times oldword appears in the string
            count++;
            i = i + oldWordLength - 1;
        }
    }
    resultString = (char *)malloc(i + count * (newWordLength - oldWordLength) + 1);
    i = 0;
    while (*str)
    {
        if (strstr(str, oldWord) == str)
        {
            strcpy(&resultString[i], newWord);
            i += newWordLength;
            str += oldWordLength;
        }
        else
        {
            resultString[i] = *str;
            i += 1;
            str += 1;
        }
    }
    resultString[i] = '\0';
    return resultString;
}
void main()
{
    char name[100], item[200], outlet[200];
    printf("Enter name of Customer : ");
    gets(name);
    printf("Enter Item Bought : ");
    gets(item);
    printf("Enter name of Outlet : ");
    gets(outlet);
    FILE *ptr = NULL;
    FILE *ptr2 = NULL;
    ptr = fopen("bill.txt", "r");
    ptr2 = fopen("billPrint.txt", "w");
    char str[200];
    fgets(str, 200, ptr);
    char *newStr;
    newStr = replaceWord(str, "{{item}}", item);
    newStr = replaceWord(newStr, "{{outlet}}", outlet);
    newStr = replaceWord(newStr, "{{name}}", name);
    fputs(newStr, ptr2);
    fclose(ptr);
    fclose(ptr2);
}