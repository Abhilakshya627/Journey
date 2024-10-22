/*Rock, Papper, Scissors Game*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int gennum(int n)
{
    srand(time(NULL));
    return rand()%n;
}
void main()
{
    int p1=0,cp=0,c=0,ch,comp;
    char name[100];
    printf("RULES of the game\n1. First to 5 points wins\n2. Wrong choice result in automaic lost\n3. Each win gives +1 points\n");
    printf("Enter Player Name : ");
    scanf("%s",&name);
    while(c==0)
    {
        if(p1==5 || cp==5)
        {
            c++;
            continue;
        }
        printf("Choose :\n1. Rock\t\t2.Paper\t\t3.Scissors\n");
        scanf("%d",&ch);
        comp=gennum(3);
        printf("The Computer Choose :\t\t");
        switch(comp+1)
        {
            case 1 : 
            printf("Rock");
            break;
            case 2 : 
            printf("Paper");
            break;
            case 3 : 
            printf("Scissor");
            break;
            default:
            printf("Unable to choose automatically lost");
        }
        printf("\n");
        printf("%s Choose :\t\t",name);
        switch(ch)
        {
            case 1 : 
            printf("Rock");
            break;
            case 2 : 
            printf("Paper");
            break;
            case 3 : 
            printf("Scissor");
            break;
            default:
            printf("Unable to choose automatically lost");
        }
        printf("\n");
        if((comp+1)==ch)
        {
            printf("Draw !!\nPlay Again\n");
        }
        else
        {
            if(comp==0)
            {
                if(ch==2)
                {
                    printf("Player wins!!\n+1 Point to %s\n",name);
                    p1++;
                }
                else
                {
                    printf("Computer wins!!\n+1 Point to Computer\n");
                    cp++;
                }
            }
            if(comp==1)
            {
                if(ch==3)
                {
                    printf("Player wins!!\n+1 Point to %s\n",name);
                    p1++;
                }
                else
                {
                    printf("Computer wins!!\n+1 Point to Computer\n");
                    cp++;
                }
            }
            if(comp==2)
            {
                if(ch==1)
                {
                    printf("Player wins!!\n+1 Point to %s\n",name);
                    p1++;
                }
                else
                {
                    printf("Computer wins!!\n+1 Point to Computer\n");
                    cp++;
                }
            }
        }
    }
    printf("!!!Game Over!!!\n");
    if(p1==5)
    printf("The Winner is : %s\n",name);
    else
    printf("The Winner is : Computer\n");
    printf("Scores :\n%s : %d\nComputer : %d",name,p1,cp);
}