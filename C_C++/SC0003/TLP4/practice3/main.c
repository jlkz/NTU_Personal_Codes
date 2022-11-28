#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *stringrChr(char *s, char ch);
int main()
{
   char s[80], c, *p;
   char *temp=NULL;

   printf("Enter a string: \n");
   fgets(s, 80, stdin);
   if (p=strchr(s,'\n')) *p = '\0';
   printf("Enter a char: \n");
   scanf("%c", &c);
   temp = stringrChr(s, c);
   if (temp!=NULL)
      printf("stringrChr(): %s\n", temp);
   else
      printf("stringrChr(): null string\n");
   return 0;
}
char *stringrChr(char *s, char ch)
{
    char* p, *q;
    int i;
    p = '\0';
    q = s;
    for(i=0; i<strlen(s); i++)
    {
        if(*q != '\0')
            {
                if(*q == ch)
                {
                p = q;
                }
            }
        q++;
    }
    return p;
}
