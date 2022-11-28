#include <stdio.h>
#include <stdlib.h>

void specialNumbers1D(int ar[], int num, int *size);
int main()
{
   int a[20],i,size=0,num;

   printf("Enter a number (between 100 and 999): \n");
   scanf("%d", &num);
   specialNumbers1D(a, num, &size);
   printf("specialNumbers1D(): ");
   for (i=0; i<size; i++)
      printf("%d ",a[i]);
   return 0;
}
void specialNumbers1D(int ar[], int num, int *size)
{
   int x, sum, a, b, c;
   for(x=100;x<=num;x++)
   {
       a=x%10;
       b=(x / 10) % 10;
       c=(x / 100) % 10;


       sum = a*a*a + b*b*b + c*c*c;

       if(x == sum)
       {

            ar[*size] = sum;
            (*size)++;
       }
   }
}
