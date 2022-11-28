#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    float gp, tx, np;
    printf("Enter hours:\n");
    scanf("%d", &t);
    if(t >= 40){
        gp = 40 * 6 + (t-40)*9;
    } else gp = t*6;
    printf("Gross pay: %.2f\n", gp);
    if(gp <= 1000){
        tx = 0.1 * gp;
    }else if (gp>1000 && gp<=1500){
        tx = 0.1*1000 + 0.2*(gp-1000);
    }else{
        tx = 0.1*1000 + 0.2*500 + 0.3*(gp-1500);
    }
    printf("Tax: %.2f\n", tx);
    np = gp - tx;
    printf("Nett pay: %.2f\n", np);
    return 0;
}
