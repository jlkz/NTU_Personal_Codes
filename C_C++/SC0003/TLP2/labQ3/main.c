#include <stdio.h>
#include <stdlib.h>
int square1(int num);
void square2(int num, int *result);

int main()
{
   int number, result=0;
   printf("Enter the number: \n");
   scanf("%d", &number);
   printf("square1(): %d\n", square1(number));
   square2(number, &result);
   printf("square2(): %d\n", result);
   return 0;
}
int square1(int num)
{
   int count, x=0;
   for(count=0; count<num; count++){
    x += (1 + 2*count);
   }
   return x;
}
void square2(int num, int *result)
{
   int count;
   for(count=0; count<num; count++){
    *result +=(1+ 2*count);
   }
}
