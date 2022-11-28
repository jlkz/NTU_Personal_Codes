#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, j, k;
    printf("Give number:\n");
    scanf("%d", &num);
    printf("The pattern is: \n");
    for(i=1; i<=num; i++){
            for(j=i; j<i+i; j++){
                k = j%10;
                printf("%d", k);
            }
            printf("\n");

    }

    return 0;
}
