#include <stdio.h>
void main()
{
    float a, b, sum, dif, div, pro;
    int ch, c = 0;
    while (c == 0)
    {
        printf("Enter your choice :\n1.Add\t\t2.Subtract\t\t3.Multiply\t\t4.Divide\t\t5.Exit\n ");
        scanf("%d", &ch);
        if (ch != 5)
        {
            printf("Enter 1st Number : ");
            scanf("%f", &a);
            printf("Enter 2nd Number : ");
            scanf("%f", &b);
        }
        switch (ch)
        {
        case 1:
            sum = a + b;
            printf("The sum of %0.2f and %0.2f is %0.2f\n", a, b, sum);
            break;
        case 2:
            dif = a - b;
            printf("The difference of %0.2f and %0.2f is %0.2f\n", a, b, dif);
            break;
        case 3:
            pro = a * b;
            printf("The product of %0.2f and %0.2f is %0.2f\n", a, b, pro);
            break;
        case 4:
            div = a / b;
            printf("The quotient of %0.2f and %0.2f is %0.2f\n", a, b, div);
            break;
        case 5:
            c++;
            printf("Program ended sucessfully\n");
            break;
        default:
            printf("Enter a correct choice\n");
        }
    }
}