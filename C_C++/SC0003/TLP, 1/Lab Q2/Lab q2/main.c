#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0, count, item;
    float avg, sum = 0.0, run = 0.0;
    printf("Enter number of lines:\n");
    scanf("%d", &num);
    for (count = 1; count<= num; count++)
    {
        printf("Enter line %d (end with -1)\n", count);
        scanf("%d", &item);
        while(item != -1)
        {
            run++;
            sum += item;
            scanf("%d", &item);
        }
        avg = sum / run;
        printf("Average: %.2f\n", avg);
        run = 0;
        sum = 0;

    }


    return 0;
}
