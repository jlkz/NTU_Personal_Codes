#include <stdio.h>
#include <stdlib.h>

#define INIT_VALUE -1
int extEvenDigits1(int num);
void extEvenDigits2(int num, int *result);
int main()
{
   int number, result = INIT_VALUE;

   printf("Enter a number: \n");
   scanf("%d", &number);
   printf("extEvenDigits1(): %d\n", extEvenDigits1(number));
   extEvenDigits2(number, &result);
   printf("extEvenDigits2(): %d\n", result);
   return 0;
}
int extEvenDigits1(int num)
{
   int x, result=0;
   while(num!=0)
   {
       x = num%10;
       num/=10;
       if(x%2==0)
       {
            result *=10;
            result +=x;
       }
       else
       {
           continue;
       }
   }
   x=0;
   while(result !=0)
   {
       x*=10;
       x += result%10;
       result/=10;
   }
   if(x!=0)
   {
     return x;
   }
   else
   {
       return -1;
   }

}
void extEvenDigits2(int num, int *result)
{
   int x, resul=0;
   while(num!=0)
   {
       x = num%10;
       num/=10;
       if(x%2==0)
       {
            resul *=10;
            resul +=x;
       }
       else
       {
           continue;
       }
   }
   x=0;
   while(resul !=0)
   {
       x*=10;
       x += resul%10;
       resul/=10;
   }
   if(x!=0)
   {
     *result = x;
   }
   else
   {
        *result = -1;
   }

}
