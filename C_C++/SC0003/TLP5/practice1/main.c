#include <stdio.h>
#include <stdlib.h>
typedef struct {
   char name[20];
   int age;
} Person;
void readData(Person *p);
Person findMiddleAge(Person *p);
int main()
{
   Person man[3], middle;

   readData(man);
   middle = findMiddleAge(man);
   printf("findMiddleAge(): %s %d\n", middle.name, middle.age);
   return 0;
}
void readData(Person *p)
{
    printf("Enter person 1:\n ");
    scanf("%s %d", p[0].name, &p[0].age);
    printf("Enter person 2:\n ");
    scanf("%s %d", p[1].name, &p[1].age);
    printf("Enter person 3:\n ");
    scanf("%s %d", p[2].name, &p[2].age);
}
Person findMiddleAge(Person *p)
{
    int max, min, i, mid;
    max = min = p[0].age;
    for(i=0; i<3; i++)
    {
        if(p[i].age>max)
        {
            max = p[i].age;
        }
        if(p[i].age<min)
        {
            min = p[i].age;
        }
    }
    for(i=0;i<3;i++)
    {
        if(p[i].age < max && p[i].age > min)
        {
            mid = i;
        }
    }
    return p[mid];
}

