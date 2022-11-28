#include <stdio.h>
#include <stdlib.h>

int main()
{
    int price, cat;
    float lt,f;
    printf("List price: \n");
    scanf("%d", &price);
    printf("CAtegory:\n");
    scanf("%d", &cat);
    price = price * 0.9;
    if (price >= 100000){
        lt = 0.1*(price-100000);
    }else lt =0;
    switch(cat){
        case 1: f = (price * 1.03)+lt+70000;
        break;
        case 2: f = (price * 1.03)+lt+80000;
        break;
        case 3: f = (price * 1.03)+lt+23000;
        break;
        case 4: f = (price * 1.03)+lt+600;
        break;
    }
    printf("Total price = $%.2f", f);



    return 0;
}
