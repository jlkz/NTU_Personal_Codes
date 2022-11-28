#include <stdio.h>
#include <stdlib.h>

int main()
{
    int l, j ,i, len, total=0, num;
    printf("Number of times:\n");
    scanf("%d", &l);
    for (j=1; j<=l; j++){
        printf("Enter line %d:\n", j);
        scanf("%d", &len);

        for(i=1; i<=len; i++){
            scanf("%d", &num);
            total += num;
        }
        printf("Total is: %d\n", total);
        total = 0;
    }

    return 0;
}
