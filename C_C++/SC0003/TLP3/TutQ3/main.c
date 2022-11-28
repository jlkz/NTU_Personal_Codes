#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
void transpose2D(int ar[][SIZE], int rowSize, int colSize);
int x, y;
int main()
{
    int array[SIZE][SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    transpose2D(array, SIZE, SIZE);
    for(x=0; x<4; x++)
    {
        for(y=0; y<4; y++)
        {
            printf("%d ", array[x][y]);
        }
        printf("\n");
    }
    return 0;
}

void transpose2D(int ar[][SIZE], int rowSize, int colSize)
{
    int dick[SIZE][SIZE];
    for(x=0; x<rowSize; x++)
    {
        for(y=0; y<colSize; y++)
        {
            dick[y][x] = ar[x][y];
        }
    }
    for(x=0; x<rowSize; x++)
    {
        for(y=0; y<colSize; y++)
        {
            ar[y][x] = dick[y][x];
        }
    }
}
