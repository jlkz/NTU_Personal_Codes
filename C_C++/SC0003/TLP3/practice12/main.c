#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize);
int main()
{
   int data[SIZE][SIZE];
   int i,j;
   int rowSize, colSize;
   printf("Enter the array size (rowSize, colSize): \n");
   scanf("%d %d", &rowSize, &colSize);
   printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
   for (i=0; i<rowSize; i++)
      for (j=0; j<colSize; j++)
         scanf("%d", &data[i][j]);
   printf("compress2D(): \n");
   compress2D(data, rowSize, colSize);
   return 0;
}
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize)
{
   int i, j, move, count;
   for(i=0; i< rowSize; i++)
   {
       for(j=0; j<colSize; j++)
       {
           count = 1;
           if(data[i][j]==1)
           {
               printf("1 ");
               for(move=1; move+j<colSize; move++)
               {
                   if(data[i][j+move]== 1)
                   {
                       count++;
                   }
                   else
                   {
                       //j += count-1;
                       break;
                   }
               }
               j += count-1;
               printf("%d ", count);
               count = 1;
           }
           if(data[i][j]==0)
           {
               printf("0 ");
               for(move=1; move+j<colSize; move++)
               {
                   if(data[i][j+move]== 0)
                   {
                       count++;
                   }
                   else
                   {
                       break;
                   }
               }
               j += count-1;
               printf("%d ", count);
               count = 1;
           }
       }
       printf("\n");
   }

}
