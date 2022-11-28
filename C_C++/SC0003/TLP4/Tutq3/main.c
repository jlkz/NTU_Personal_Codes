#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stringcpy(char*s1, char *s2, int n);
int main()
{
    int num;
    char s1 [20], s2[20], *p;
    printf("Enter string: \n");
    fgets(s2, 20, stdin);
    if ((p=strchr(s2,'\n')))
    {
        *p= '\0';
    }
    printf("Enter number of characters:\n");
    scanf("%d", &num);
    printf("stringcpy(): %s", stringcpy(s1, s2, num));


    return 0;
}

char *stringcpy(char*s1, char *s2, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        *(s1+i) = s2[i];
    }
    return s1;
}

