#include <stdio.h>
#include <stdlib.h>

int sumSqDigits1(int num);
void sumSqDigits2(int num, int *result);
int main()
{
   int num, result = 0;
   printf("Enter a number: \n");
   scanf("%d", &num);
   printf("sumSqDigits1(): %d\n", sumSqDigits1(num));
   sumSqDigits2(num, &result);
   printf("sumSqDigits2(): %d\n", result);
   return 0;
}
int sumSqDigits1(int num)
{
   int x;
   while(num!=0)
   {
       x+= (num%10) * (num%10);
       num /= 10;
   }
   return x;
}
void sumSqDigits2(int num, int *result)
{
   while(num!=0)
   {
        (*result)+= (num%10) * (num%10);
       num /= 10;
   }
}
