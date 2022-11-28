#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void processString(char *str, int *totVowels, int *totDigits);
int main()
{
   char str[50], *p;
   int totVowels, totDigits;
   printf("Enter the string: \n");
   fgets(str, 80, stdin);
   if (p=strchr(str,'\n')) *p = '\0';
   processString(str, &totVowels, &totDigits);
   printf("Total vowels = %d\n", totVowels);
   printf("Total digits = %d\n", totDigits);
   return 0;
}
void processString(char *str, int *totVowels, int *totDigits)
{
    int x;
    *totVowels = *totDigits = 0;
    for(x=0; x<strlen(str); x++)
    {
        if(isdigit(str[x]))
        {
            (*totDigits)++;
        }
        if(isalpha(str[x]))
        {
            if(toupper(str[x]) == 'A' ||toupper(str[x]) == 'E'||toupper(str[x]) == 'I'||toupper(str[x]) == 'O'||toupper(str[x]) == 'U')
            {
                (*totVowels)++;
            }

        }
    }
}
