#include <stdio.h>
#include <stdlib.h>


int main()
{
    char x;
    printf("Enter char\n");
    scanf("%c", &x);
    if(isupper(x)) printf("Upper\n");
    else if (islower(x)) printf("Lower\n");
    else if (isdigit(x)) printf("Digit\n");
    else printf("Other\n");
    return 0;
}
