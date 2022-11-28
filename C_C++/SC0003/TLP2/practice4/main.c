#include <stdio.h>
#include <stdlib.h>

float power1(float num, int p);
void power2(float num, int p, float *result);
int main()
{
   int power;
   float number, result=-1;

   printf("Enter the number and power: \n");
   scanf("%f %d", &number, &power);
   printf("power1(): %.2f\n", power1(number, power));
   power2(number,power,&result);
   printf("power2(): %.2f\n", result);
   return 0;
}
float power1(float num, int p)
{
   float temp = 1;
   int count;
   if (p>0){
   for (count =1; count<=p; count++){
        temp *= num;
        }
   }
   else if (p<0){
        for (count =0; count>p; count--){
                temp *= num;
        }
        temp = 1/temp;
   } else{
   temp = 1;
   }
   return temp;
}
void power2(float num, int p, float *result)
{
   int count;
   (*result) += 2;
   if (p<0){
        for (count =0; count>p; count--){
            (*result) *= num;
        }
            *result = 1/(*result);
   }


   else if(p>0){
   for (count =1; count<=p; count++){
            (*result) *= num;
   }
   }
   else{
    *result = 1;
   }
}
