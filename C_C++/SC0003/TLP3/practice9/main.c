#include <stdio.h>
#include <stdlib.h>

void swapMinMax1D(int ar[], int size);
int main()
{
   int ar[50],i,size;

   printf("Enter array size: \n");
   scanf("%d", &size);
   printf("Enter %d data: \n", size);
   for (i=0; i<size; i++)
      scanf("%d",ar+i);
   swapMinMax1D(ar, size);
   printf("swapMinMax1D(): ");
   for (i=0; i<size; i++)
      printf("%d ",*(ar+i));
   return 0;
}
void swapMinMax1D(int ar[], int size)
{
  int *p, *q, x, temp, min, max;
  min = max = ar[0];
  for(x=0; x<size; x++)
  {
      if(ar[x]>= max)
      {
          max = ar[x];
          p = &ar[x];
      }
      if(ar[x]<= min)
      {
          min = ar[x];
          q = &ar[x];
      }
  }
  temp = *p;
  *p = *q;
  *q = temp;
}
