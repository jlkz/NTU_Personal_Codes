#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void maxCharToFront(char *str);
int main()
{
   char str[80], *p;

   printf("Enter a string: \n");
   fgets(str, 80, stdin);
   if (p=strchr(str,'\n')) *p = '\0';
   printf("maxCharToFront(): ");
   maxCharToFront(str);
   puts(str);
   return 0;
}
void maxCharToFront(char *str)
{
	/*edit*/
   char *cp;
   int i=1, max=0, j;

   for(;i<strlen(str); i++)
   {
    if(str[i]>str[max])
    {
        max = i;
    }
   }
   cp[0] = str[max];
   for(j=0; j<max; j++ )
   {
       cp[1+j] = str[j];
   }
   for(j=max+1; j<strlen(str); j++ )
   {
       cp[j] = str[j];
   }
   for(i=0; i<strlen(str); i++)
   {
       str[i]=cp[i];
   }


	/*end_edit*/
}
