#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num, count;
    float x1, x2, y1, y2, sum, ans;
    printf("num: \n");
    scanf("%d", &num);
    for(count =1; count<=num; count++){
        printf("Enter first pt x1 y1\n");
        scanf("%f %f", &x1, &y1);
        printf("Enter the second pt x2 y2\n");
        scanf("%f %f", &x2, &y2);
        sum = (x1 - x2)*(x1-x2) + (y1-y2)*(y1-y2);
        ans = sqrt(sum);
        printf("Distance is %.2f\n", ans);

    }
    return 0;
}
