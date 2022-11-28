#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, i, j;
    printf("Give number:\n");
    scanf("%d", &row);
    printf("The pattern: \n");
    for(i=1; i<=row; i++){
        if(i%2==1){
            for(j=1; j<=i; j++){
                if(j%2==1){
                    printf("A");
                }
                else{printf("B");
                }
            } printf("\n");
        }
        else if(i%2==0){
                for(j=1; j<=i; j++){
                if(j%2==1){
                    printf("B");
                }
                else{printf("A");
                }
            } printf("\n");

        }
    }

    return 0;
}
