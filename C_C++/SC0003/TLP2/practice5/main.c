#include <stdio.h>
#include <stdlib.h>

int gcd1(int num1, int num2);
void gcd2(int num1, int num2, int *result);
int main()
{
   int x,y,result=-1;
   printf("Enter 2 numbers: \n");
   scanf("%d %d", &x, &y);
   printf("gcd1(): %d\n", gcd1(x, y));
   gcd2(x,y,&result);
   printf("gcd2(): %d\n", result);
   return 0;
}
int gcd1(int num1, int num2)
{
   int i;
   if (num1<num2){
    for(i=num1; i>0; i--){
        if(num1%i ==0 && num2%i==0){
            return i;
        }else continue;
    }return 1;
   }else if (num1>num2){
             for(i=num2; i>0; i--){
        if(num1%i ==0 && num2%i==0){
            return i;
        }else continue;
    }return 1;
    }else return num1;
}
void gcd2(int num1, int num2, int *result)
{
    int i;
    if (num1<num2)
    {
        for(i=num1; i>0; i--)
        {
            if(num1%i ==0 && num2%i==0)
            {
                *result = i;
                break;
            }
            else
            {
                continue;
            }
        }

    }

    else if (num1>num2)
        {
        for(i=num2; i>0; i--){
        if(num1%i ==0 && num2%i==0)
        {
            *result = i;
            break;
        }
        else
        {
            continue;
        }
    }

    }
    else *result = num1;
}
