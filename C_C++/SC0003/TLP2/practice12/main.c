#include <stdio.h>
#include <stdlib.h>

int allOddDigits1(int num);
void allOddDigits2(int num, int *result);
int main()
{
   int number, p=999, result=999;
   printf("Enter a number: \n");
   scanf("%d", &number);
   p = allOddDigits1(number);
   if (p == 1)
      printf("allOddDigits1(): yes\n");
   else
      printf("allOddDigits1(): no\n");
   allOddDigits2(number, &result);
   if (result == 1)
      printf("allOddDigits2(): yes\n");
   else
      printf("allOddDigits2(): no\n");
   return 0;
}
int allOddDigits1(int num)
{
   int x, p=1;
   while(num!=0)
   {
       x = num%10;
       num/=10;
       if(x%2==1)
       {
           continue;
       }
       else
       {
           p = 0;
           break;
       }
   }
   return p;
}
void allOddDigits2(int num, int *result)
{
   int x;
   while(num!=0)
   {
       x = num%10;
       num/=10;
       if(x%2==1)
       {
            *result =1;
       }
       else
       {
           *result = 0;
           break;
       }
   }
}
