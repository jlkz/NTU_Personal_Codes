#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, count;
    float i, r, p;
    printf("NUmber of times: \n");
    scanf("%d", &num);
    for (count = 1; count <= num; count++){
        printf("Enter current: \n");
        scanf("%f", &i);
        printf("Enter resistance: \n");
        scanf("%f", &r);
        p = i * i * r;
        printf("The power loss is %.2f\n", p);
    }

    return 0;
}
