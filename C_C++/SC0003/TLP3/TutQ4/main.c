#include <stdio.h>
#include <stdlib.h>
#define size 4
void reduceMatrix2D(int ar[][size], int rowSize, int colSize);
int sum, x, y;
int main()
{
    int a[size][size] = {4,3,8,6,9,0,6,5,5,1,2,4,9,8,3,7};
    reduceMatrix2D(a, size, size);
    for(x=0; x<size; x++)
    {
        for(y=0; y<size; y++)
        {
            printf("%d ", a[x][y]);
        }
        printf("\n");
    }
    return 0;
}

void reduceMatrix2D(int ar[][size], int rowSize, int colSize)
{

    for(x=0; x<colSize; x++)
    {
        sum=0;
        for(y=0; y<rowSize; y++)
        {
            if(y > x)
            {
                sum+= ar[y][x];
                ar[y][x] = 0;
            }
        }
        ar[x][x] += sum;

    }
}
