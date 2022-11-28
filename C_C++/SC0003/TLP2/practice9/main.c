#include <stdio.h>
#include <stdlib.h>

int countEvenDigits1(int number);
void countEvenDigits2(int number, int *count);
int main()
{
   int numb, result =0;
   printf("Enter a number: \n");
   scanf("%d", &numb);
   printf("countEvenDigits1(): %d\n", countEvenDigits1(numb));
   countEvenDigits2(numb, &result);
   printf("countEvenDigits2(): %d\n", result);
   return 0;
}
int countEvenDigits1(int number)
{
   int x, y=0;
   while(number!=0)
   {
       x = number%10;
       number /=10;
       if(x%2 ==0)
       {
           y++;
       }
       else
       {
           continue;
       }
   }
   return y;
}
void countEvenDigits2(int number, int *count)
{
   int x;
   while(number!=0)
   {
       x = number%10;
       number/= 10;
       if(x%2 ==0)
       {
           (*count)++;
       }
       else
       {
           continue;
       }
   }
}
