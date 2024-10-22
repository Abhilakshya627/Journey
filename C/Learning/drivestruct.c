/*Construct a programme to input and print details of n drivers of your agency.
The details must be as follows:
Name of the Driver
Driving License Number
Route
Kms Driven
*/
#include <stdio.h>
#include <string.h>
struct ds
{
    char name[100];
    char dl[17];
    char route[200];
    int kms;
};
void main()
{
    int n, i;
    struct ds d1, d2, d3;
    printf("\nEnter details of First Driver."); // 1st Driver Entry
    printf("\nEnter name of the driver : ");
    scanf("%s", &d1.name);
    printf("\nEnter Driving License Number of the driver : ");
    scanf("%s", &d1.dl);
    printf("\nEnter route of the driver : ");
    scanf("%s", &d1.route);
    printf("\nEnter Kms driven by the driver : ");
    scanf("%d", &d1.kms);
    printf("\nEnter details of Second Driver."); // 2nd Diver Entry
    printf("\nEnter name of the driver : ");
    scanf("%s", &d2.name);
    printf("\nEnter Driving License Number of the driver : ");
    scanf("%s", &d2.dl);
    printf("\nEnter route of the driver : ");
    scanf("%s", &d2.route);
    printf("\nEnter Kms driven by the driver : ");
    scanf("%d", &d2.kms);
    printf("\nEnter details of Third Driver."); // 3rd Driver Entry
    printf("\nEnter name of the driver : ");
    scanf("%s", &d3.name);
    printf("\nEnter Driving License Number of the driver : ");
    scanf("%s", &d3.dl);
    printf("\nEnter route of the driver : ");
    scanf("%s", &d3.route);
    printf("\nEnter Kms driven by the driver : ");
    scanf("%d", &d3.kms);
    printf("\n#####Printing Information#####");
    printf("\nDriver 1 :"); // Driver 1 Print
    printf("\nName of the driver : %s", d1.name);
    printf("\nDL No. of the driver : %s", d1.dl);
    printf("\nRoute of the driver : %s", d1.route);
    printf("\nKilometers driven by the driver : %d", d1.kms);
    printf("\nDriver 2 :"); // Driver 2 Print
    printf("\nName of the driver : %s", d2.name);
    printf("\nDL No. of the driver : %s", d2.dl);
    printf("\nRoute of the driver : %s", d2.route);
    printf("\nKilometers driven by the driver : %d", d2.kms);
    printf("\nDriver 3 :"); // Driver 3 Print
    printf("\nName of the driver : %s", d3.name);
    printf("\nDL No. of the driver : %s", d3.dl);
    printf("\nRoute of the driver : %s", d3.route);
    printf("\nKilometers driven by the driver : %d", d3.kms);
}