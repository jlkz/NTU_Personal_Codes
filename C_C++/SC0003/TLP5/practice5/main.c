#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
   char name[20]; /* student name */
   double testScore; /* test score */
   double examScore; /* exam score */
   double total;  /* total = (testScore+examScore)/2 */
};
double average();
int main()
{

   printf("average(): %.2f\n", average());
   return 0;
}
double average()
{
   int i=0, j;
   double average = 0.00;
   char dummy, *p;
   struct student list[50];
   printf("Enter student name: \n");
   fgets(list[i].name, 50, stdin);
   if(p=strchr(list[i].name, '\n')) *p='\0';
   while(strcmp(list[i].name, "END") != 0)
   {
       printf("Enter test score: \n");
       scanf("%lf", &(list[i].testScore));
       printf("Enter exam score: \n");
       scanf("%lf", &(list[i].examScore));
       list[i].total = (list[i].testScore + list[i].examScore)/2;
       printf("Student %s total = %.2lf\n", list[i].name, list[i].total );
       i++;
       printf("Enter student name: \n");
       scanf("%c", &dummy);
       fgets(list[i].name, 50, stdin);
       if(p=strchr(list[i].name, '\n')) *p = '\0';
   }
   if(i>0)
   {
     for (j=0; j<i; j++)
    {
       average += list[j].total;
    }
    average /= i;
   }

   return average;
}
