#include <stdio.h>
#include <stdlib.h>

int digitPos1(int num, int digit);
void digitPos2(int num, int digit, int *result);
int main()
{
   int number, digit, result=0;
   printf("Enter the number: \n");
   scanf("%d", &number);
   printf("Enter the digit: \n");
   scanf("%d", &digit);
   printf("digitPos1(): %d\n", digitPos1(number, digit));
   digitPos2(number, digit, &result);
   printf("digitPos2(): %d\n", result);
   return 0;
}
int digitPos1(int num, int digit)
{
   int result;
   do{
    result++;
    if(num%10 == digit){
        return result;
    }
    else{
        num = num/10;
    }
   }while( num > 0);
    return 0    ;
}
void digitPos2(int num, int digit, int *result)
{
    int pos=0;
    *result=0;
    do {
       pos++;
       if (num%10 == digit){
         *result = pos;
         break;
       }
       num = num/10;
    } while (num > 0);
}
