#include <stdio.h>
#include <stdlib.h>
void collect(int ar[], int size);
void hist(int ar[], int size);

int y, x;
int main()
{
    int array[10];
    collect(array, 10);
    hist(array, 10);
    return 0;
}

void collect(int ar[], int size)
{
    for(y=0; y<10; y++ )
    {
        ar[y] = rand()%100;
    }
}

void hist(int ar[], int size)
{
    for(y=0; y<10; y++)
    {
        printf("%d - %d   |", y*10, y*10+9);
        for(x=0; x<ar[y]; x++)
        {
            printf("*");
        }
        printf("\n");
    }

}
