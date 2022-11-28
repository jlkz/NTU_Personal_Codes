#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>



int bottom_up_dp(int n, int *s, int *v, int C)
{
    int ** M;
    int i, j;
    M = (int **)malloc((n+1) *sizeof(int*));
    for(i=0; i<=n; i++)
    {
        M[i] = (int *)malloc((C+1)* sizeof(int));
    }
     for(i=0;i<=n;i++)
     {
         for(j=0;j<=C;j++)
         {
              M[i][j] = 0;
         }
     }


    for(i=1; i<=n; i++)
    {
        // try for each item to see if fit, more value than not adding
        for(j=1; j<=C; j++)
        {
            if(j-s[i] < 0)
            {
                M[i][j] = M[i-1][j];
                //printf("n %d C %d", i, j);
                continue;
            }
            if(M[i-1][j] > M[i-1][j-s[i]]+v[i])
            {
                M[i][j] = M[i-1][j];
            }
            else
            {
                M[i][j] = M[i-1][j-s[i]]+v[i];
            }

        }
    }
    for(i=0;i<=n;i++)
     {
         for(j=0;j<=C;j++)
         {
              printf("%d ",M[i][j]);
         }
         printf("\n");
     }
    return M[i-1][j-1];

}


int main ()
{
    int n,C;
    int function;
    int *s;
    int *v;
    int i,j;

    printf("Enter the number of items n:\n");
    scanf("%d",&n);
    printf("Enter the capacity C:\n");
    scanf("%d",&C);
    s = (int *) malloc(sizeof(int) * (n+1));
    v = (int *) malloc(sizeof(int) * (n+1));

    printf("Enter the sizes of items (as a list, separate by spacing:\n");
    for (i=1;i<=n;i++)
        scanf("%d",&s[i]);

    printf("Enter the values of items (as a list, separate by spacing:\n");
    for (i=1;i<=n;i++)
        scanf("%d",&v[i]);

    printf("The maximum value is: %d \n", bottom_up_dp(n,s,v,C));

}
