#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x, y,a1,a2,b1,b2,c1,c2;
    printf("Enter a1 b1 c1 a2 b2 c2: \n");
    scanf("%f %f %f %f %f %f", &a1,&b1,&c1,&a2,&b2,&c2);
    x = (b2*c1-b1*c2)/(a1*b2-a2*b1);
    y = (a1*c2-a2*c1)/(a1*b2-a2*b1);
    if ((a1*b2-a2*b1) == 0){
        printf("Denominator is 0");
    }
    else{
     printf("x=%.2f y=%.2f",x,y);
    }


    return 0;
}
