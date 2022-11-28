#include <stdio.h>
#include <stdlib.h>
void printReverse1(int ar[], int size);
void printReverse2(int ar[], int size);

void reverseAr1D(int ar[], int size);
int main()
{
   int ar[20];
   int size, i;

   printf("Enter array size: \n");
   scanf("%d", &size);
   printf("Enter %d data: \n", size);
   for (i=0; i <= size-1; i++)
      scanf("%d", &ar[i]);
   printReverse1(ar, size);
   printReverse2(ar, size);
   reverseAr1D(ar, size);
   printf("reverseAr1D(): ");
   if (size > 0) {
      for (i=0; i<size; i++)
         printf("%d ", ar[i]);
   }
   return 0;
}
void printReverse1(int ar[], int size)
{
   int x;
   for(x=0;x<size; x++)
   {
       printf("%d ", ar[size-x-1]);
   }
   printf("\n");
}
void printReverse2(int ar[], int size)
{
    int x, *ptr;
    ptr = ar + size - 1;
    for(x=0;x<size; x++)
   {
       printf("%d ", *ptr--);
   }
   printf("\n");

}
void reverseAr1D(int ar[ ], int size)
{
    int x, y, b[size];
   for(x=0; x<size; x++)
   {
        b[x] = ar[size-x-1];
        printf("%d", b[x]);
   }
   for(y=0; y<size; y++)
   {
       ar[y] = b[y];
   }
}
