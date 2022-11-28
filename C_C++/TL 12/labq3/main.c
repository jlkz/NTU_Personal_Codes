#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//memory
int *r;


int cr_bottom_up_dp_print(int *p, int n)
{
    int j, i;
    int * combi;
    combi = malloc(sizeof(int) * (n+1));
    int small, big;
    for (i=0; i<=n; i++)
    {
        r[i] = 0;
    }
    for(j=1; j<=n; j++)
    {
        for(i=1; i<=j;i++)
        {
            if(r[j]<p[i]+r[j-i])
            {
                small = i;
                big = j-i;
                r[j] = p[i]+r[j-i];
            }
        }
        combi[j] = small;

    }
    i= r[n];
    while(1)
    {
        printf("%d + ", combi[n]);
        n = n - combi[n];
        if(n == 0)
        {
            printf("0\n");
            break;
        }
    }
    //printf("Small: %d, Big: %d\n", small, big);
    return i;
}


void main ()
{
    int n;      //length of  rod
    int function;
    int i;
    int *p;     //price list

    int price_list[10] = {0,1,4,8,9,10,17,17,20,24}; //declare one more value to cover the index 0;

    n = sizeof(price_list) / sizeof(int) - 1;
    n = 9;
    p = price_list;


    //allocate the memory array
    r = malloc(sizeof(int) * (n+1));


    //set all memory elements to -1
    for (i=0; i<=n; i++)
        r[i] = -1;

    printf("The maximun value is: %d \n", cr_bottom_up_dp_print(p,n));
}
