#include <stdio.h>
#include <stdlib.h>
int platform1D(int ar[], int size);
int main()
{
   int i,b[50],size;
   printf("Enter array size: \n");
   scanf("%d", &size);
   printf("Enter %d data: \n", size);
   for (i=0; i<size; i++)
      scanf("%d",&b[i]);
   printf("platform1D(): %d\n", platform1D(b,size));
   return 0;
}
int platform1D(int ar[], int size)
{
   int i,j,count,x,ans=0;
   for(i=0; i<size; i++)
   {
       x=ar[i];
       count = 0;
       for(j=i; j<size; j++)
       {
           if(x == ar[j])
           {
               count++;
           }
       }
       if(count>ans)
       {
           ans = count;
       }
   }
   return ans;
}
