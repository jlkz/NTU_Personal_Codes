#include <stdio.h>
#include <stdlib.h>

int perfectProd1(int num);
void perfectProd2(int num, int *prod);

int main()
{
   int number, result=1;

   printf("Enter a number: \n");
   scanf("%d", &number);
   printf("Calling perfectProd1() \n");
   printf("perfectProd1(): %d\n", perfectProd1(number));

   printf("Calling perfectProd2() \n");
   perfectProd2(number, &result);
   printf("perfectProd2(): %d\n", result);
   return 0;
}
int perfectProd1(int num)
{
   int i, x=0, prod =1;
   for(num; num>1; num--)
   {
       for(i=1; i<num; i++)
       {
           if(num%i==0)
           {
               x+=i;
           }
           else
           {
               continue;
           }
       }
       if(x==num)
       {
           printf("Perfect number: %d\n", x);
           prod *= x;
           x = 0;
       }
       else
       {
           x = 0;
       }
   }
   return prod;
}
void perfectProd2(int num, int *prod)
{
    int i, x=0;
   for(num; num>1; num--)
   {
       for(i=1; i<num; i++)
       {
           if(num%i==0)
           {
               x+=i;
           }
           else
           {
               continue;
           }
       }
       if(x==num)
       {
           printf("Perfect number: %d\n", x);
           (*prod) *= x;
           x = 0;
       }
       else
       {
           x = 0;
       }
   }

}
