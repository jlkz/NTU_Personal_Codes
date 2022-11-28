#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct {
   char name[20];
   int telno;
} PhoneBk;
void printPB(PhoneBk *pb, int size);
int readin(PhoneBk *pb);
void search(PhoneBk *pb, int size, char *target);
int main() {
   PhoneBk s[MAX];
   char t[20], *p;
   int size=0, choice;
   char dummychar;

   printf("Select one of the following options: \n");
   printf("1: readin()\n");
   printf("2: search()\n");
   printf("3: printPB()\n");
   printf("4: exit()\n");
   do
{
      printf("Enter your choice: \n");
      scanf("%d", &choice);
      switch (choice){
         case 1:
            scanf("%c", &dummychar);
            size = readin(s);
            break;
         case 2:
            scanf("%c", &dummychar);
            printf("Enter search name: \n");
            fgets(t, 20, stdin);
            if (p=strchr(t,'\n')) *p = '\0';
            search(s,size,t);
            break;
         case 3:
            printPB(s, size);
            break;
      }
   } while (choice < 4);
   return 0;
   }
void printPB(PhoneBk *pb, int size)
{
    int i=0;
    printf("The phonebook list:\n");
    if(size == 0)
    {
        printf("Empty Phonebook\n");
    }
    for(; i<size; i++)
    {
        printf("Name: %s\n", pb[i].name);
        printf("Telno: %d\n", pb[i].telno);
    }

}
int readin(PhoneBk *pb)
{
    int x = 0;
    char *p;
    printf("Enter name: \n");
    fgets(pb[x].name, MAX, stdin);
    if(p=strchr(pb[x].name, '\n'))
    {
            *p = '\0';
    }
    printf("Enter tel: \n");
    scanf("\n");
    scanf("%d", &pb[x].telno);
    x++;
    while (1)
    {
        printf("Enter name: \n");
        scanf("\n");
        fgets(pb[x].name, MAX, stdin);
        if(p=strchr(pb[x].name, '\n'))
        {
            *p = '\0';
        }
        if (pb[x].name[0] == '#')
        {
            break;
        }
        printf("Enter tel: \n");
        scanf("\n");
        scanf("%d", &pb[x].telno);
        x++;
    }
    return x;
}
void search(PhoneBk *pb, int size, char *target)
{
    int j=-1,i;
    for(i=0; i<size; i++)
    {
        if(strcmp(target, pb->name)==0)
        {
            printf("Name = %s, Tel = %d\n", pb[i].name, pb[i].telno);
            j=i;
            break;
        }
    }
    if(j==-1)
    {
     printf("Name not found\n");
    }
}
