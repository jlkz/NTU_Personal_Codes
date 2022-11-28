#include <stdio.h>
#include <stdlib.h>

int stringcmp(char* s1, char* s2);
int main()
{
    int x;
    char s1[20], s2[20];
    printf("Enter source string: \n");
    scanf("%s", s1);
    printf("Enter target string: \n");
    scanf("%s", s2);
    x = stringcmp(s1, s2);
    if (x == 0)
    {
        printf("stringcmp(): equal");
    }
    else if (x == 1)
    {
     printf("stringcmp(): greater than") ;
    }
    else
    {
     printf("stringcmp(): lesser than");
    }

    return 0;
}

int stringcmp(char* s1, char* s2)
{
    while(*s1 != '\0' || *s2 != '\0')
    {
        if(*s1 > *s2)
        {
            return 1;
        }
        else if (*s1 < *s2)
        {
            return -1;
        }
        else
        {
            s1++;
            s2++;

        }

    }
    return 0;
}

