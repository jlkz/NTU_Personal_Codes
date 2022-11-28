#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, i, j, r;
    printf("Enter number between 1 and 9\n");
    scanf("%d", &x);
    printf("Multiplication Table:\n ");
    for (i=1; i<=x; i++){
        printf("%d ", i);
    }
    for (i=1; i<=x; i++){
        printf("\n%d ", i);
        for(j=1; j<=i; j++){
            r = j * i;
            printf("%d ", r);
        }
    }


    return 0;
}
