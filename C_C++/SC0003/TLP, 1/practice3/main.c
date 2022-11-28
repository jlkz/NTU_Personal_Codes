#include <stdio.h>
#include <stdlib.h>
#define pi 3.1416

int main()
{
    int num, count;
    float r, h, v, sa;
    printf("Number of times: \n");
    scanf("%d", &num);
    for (count = 1; count <= num; count++){
        printf("Radius: \n");
        scanf("%f", &r);
        printf("Height: \n");
        scanf("%f", &h);
        v = pi * r * r* h;
        sa = 2 * pi * r * r + 2*pi*r*h;
        printf("Volume is %.2f \n", v);
        printf("Surface Area is %.2f \n", sa);

    }
    return 0;
}
