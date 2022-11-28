#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count, num;
    float time, d, s;
    printf("Num:\n");
    scanf("%d", &num);
    for (count = 1; count <= num; count ++){
        printf("Distance: \n");
        scanf("%f", &d);
        printf("Time: \n");
        scanf("%f", &time);
        s = d / time;
        printf("The speed is %.2f km/sec \n", s);


    }
    return 0;
}
