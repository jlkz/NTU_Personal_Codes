#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x, celcius;
    printf("Enter temp in degree F: \n");
    scanf("%f", &x);
    while(x != -1){
        celcius = (x-32) * (float)5/9;
        printf("Converted degree in C: %.2f\n", celcius);
        printf("Enter temp in degree F: \n");
        scanf("%f", &x);
    }

    return 0;
}
