#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int isPalin(int number){
    int n1 = number, rev = 0;
    while (n1 > 0){
        int d = n1 % 10;
        rev = rev * 10 + d;
        n1 = n1 / 10;
    }
    if (rev == number)
        return 1;
    else
        return 0;
}
int isprime(int n)
{
    int c=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        c++;
    }
    printf("\n");
    if(c==2)
    return 1;
    else 
    return 0;
}
int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num /= 10;
    }
    return count;
}
int isArmstrong(int num) {
    int originalNum = num,numDigits = countDigits(num),sum = 0;
    while (num != 0) {
        int digit = num % 10;
        sum += pow(digit, numDigits);
        num /= 10;
    }
    return (sum == originalNum);
}
int isSumt(int n){
    int sum = 0;    
    while(n>0){
        sum += n%10;
        n/=10;
    }
    if(sum<10)
    return 1;
    else
    return 0;
}
int main(){
    int n,i,npali=0,nprime=0,narms=0,nds=0,*a;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("Enter elements :\n");
    for(i=0;i<n;i++){
        printf("enter element %d : ",i+1);
        scanf("%d",a+i);
    }
    for(i=0;i<n;i++){
        if(isPalin(a[i]))
        npali++;
        if(isprime(a[i]))
        nprime++;
        if(isArmstrong(a[i]))   
        narms++;
        if(isSumt(a[i]))
        nds++;  
    }
    printf("\nNumber of palindromes : %d\n",npali);
    printf("Number of primes : %d\n",nprime);
    printf("Number of Armstrong : %d\n",narms);
    printf("Number of elements with sum of digit less than 10 : %d\n",nds);
    free(a);

    return 0;
}   