#include <stdio.h>
#include <stdlib.h>

int main()
{
    float result = 1.0, x = 1.0, input, deno = 1.0;
    int count, times;
    printf("Enter x: \n");
    scanf("%f", &input);
    for(count = 1; count <= 10; count++){
        for(times = 1; times<= count; times++){
            deno = deno * times;
        }
        x = input * x;
        result = result + (x/deno);
        deno = 1.0;

        }


    printf("Result is %.2f \n",result);
    return 0;

}
