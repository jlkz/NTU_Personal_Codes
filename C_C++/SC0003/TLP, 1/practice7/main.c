#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int a, n = 0;
    char x;
    printf("Enter your characters(# to end):\n");
    scanf("%c", &x);
    while(x != '#'){
        if (isalpha(x)){
            a++;
        }
        else if (isdigit(x)){
            n++;
        }

        scanf("%c", &x);
    }
    printf("Number of digits: %d\nNumber of letters: %d\n",n,a);

    return 0;
}
