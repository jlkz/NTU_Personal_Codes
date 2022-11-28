#include <stdio.h>
#include <stdlib.h>

int main()
{
    int line, row, input;

    printf("Enter the height:\n");
    scanf("%d", &input);
    while (input< 1 || input >10){
        printf("Enter height(1-10):\n");
        scanf("%d", &input);
    }
    for (line = 1; line <= input; line++){
        for(row = 1; row <= line; row++){
            if(line%3 == 1 )
                printf("1");
            else if(line%3 == 2)
                printf("2");
            else if(line%3 == 0)
                printf("3");
        }
        printf("\n");

    }

    return 0;
}
