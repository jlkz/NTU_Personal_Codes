#include <stdio.h>
#include <stdlib.h>

int countOddDigits1(int num);
void countOddDigits2(int num, int *result);
int main()
{
   int number, result =0;

   printf("Enter a number: \n");
   scanf("%d", &number);
   printf("countOddDigits1(): %d\n", countOddDigits1(number));
   countOddDigits2(number, &result);
   printf("countOddDigits2(): %d\n", result);
   return 0;
}
int countOddDigits1(int number)
{
   int x, result=0;
   while(number!=0)
   {
       x=number%10;
       number/=10;
       if(x%2==1)
       {
           result++;
       }
       else
       {
           continue;
       }
   }
   return result;
}
void countOddDigits2(int number, int *count)
{
   int x;
   while(number!=0)
   {
       x=number%10;
       number/=10;
       if(x%2==1)
       {
           (*count)++;
       }
       else
       {
           continue;
       }
   }
}
