#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *sweepSpace1(char *str);
char *sweepSpace2(char *str);
void re(char*s);
int main()
{
   char str[80],str2[80], *p;

   printf("Enter the string: \n");
   fgets(str, 80, stdin);
   if (p=strchr(str,'\n')) *p = '\0';
   strcpy(str2,str);
   printf("sweepSpace1(): %s\n", sweepSpace1(str));
   printf("sweepSpace2(): %s\n", sweepSpace2(str2));
   /*re(str2);
   printf("%s", str2); */
   return 0;
}
char *sweepSpace1(char *str)
{
   int j, i;

     j = i = 0;
     do
     {
         while(str[j] == ' ')
         {
             j++;
         }
     }
     while (str[i++]=str[j++]);

   return str;
}
char *sweepSpace2(char *str)
{
   int i, j=0, x = strlen(str);
   for(i=0; i<x; i++)
   {
       if(*(str+i) != ' ')
       {
           *(str+j) = *(str+i);
           j++;
       }
   }
    *(str+j)='\0';
   return str;
}

void re(char*s)
{
    char*d=s;
    do
    {
        while(*d == ' ')
        {
           d++;
        }
    }
    while (*s++ = *d++);
}

