#include <stdio.h>
#include <stdlib.h>

int reverseDigits1(int num);
void reverseDigits2(int num, int *result);
int main()
{
   int num, result=999;
   printf("Enter a number: \n");
   scanf("%d", &num);
   printf("reverseDigits1(): %d\n", reverseDigits1(num));
   reverseDigits2(num, &result);
   printf("reverseDigits2(): %d\n", result);
   return 0;
}
int reverseDigits1(int num)
{
   int x, res =0;
   while(num!=0)
   {
       x=num%10;
       num/=10;
       res*=10;
       res+= x;
   }
   return res;
}
void reverseDigits2(int num, int *result)
{
   int x, res =0;
   while(num!=0)
   {
       x=num%10;
       num/=10;
       res*=10;
       res+= x;
   }
   *result = res;
}
