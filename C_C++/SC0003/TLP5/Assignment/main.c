#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 5

typedef struct
{
 int nameCardID;
 char personName[20];
 char companyName[20];
} NameCard;
void listNameCards(NameCard *s, int size);
int addNameCard(NameCard *s, int size);
int removeNameCard(NameCard *s, int size, char *target);
int getNameCard(NameCard *s, int size, char *target);
int main()
{
    NameCard s[MAX];
    int size=0, choice, result;
    char name[20], *p;
    printf("NTU NAME CARD HOLDER MANAGEMENT PROGRAM:\n");
    printf("1: listNameCards()\n");
    printf("2: addNameCard()\n");
    printf("3: removeNameCard()\n");
    printf("4: getNameCard()\n");
    printf("5: quit\n");
    do{
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("listNameCards():\n");
            listNameCards(s, size);
            break;
        case 2:
            printf("addNameCard():\n");
            size = addNameCard(s, size);
            break;
        case 3:
            printf("removeNameCard():\n");
            printf("Enter personName: \n");
            scanf("\n");
            fgets(name, 20, stdin);
            if(p=strchr(name, '\n'))
            {
                *p = '\0';
            }
            size = removeNameCard(s, size, name);
            break;
        case 4:
            printf("getNameCard():\n");
            printf("Enter personName: \n");
            scanf("\n");
            fgets(name, 20, stdin);
            if(p=strchr(name, '\n'))
            {
                *p = '\0';
            }
            result = getNameCard(s, size, name);
            if(result != 1)
            {
                printf("The target person name is not found \n");
            }
            break;
        }
    }while(choice<5);
    return 0;
}
void listNameCards(NameCard *s, int size)
{
    int i;
    if (size == 0)
    {
        printf("The name card holder is empty\n");
    }
    else
    {
        for(i=0; i<size; i++)
        {
            printf("nameCardID: %d\n", s[i].nameCardID);
            printf("personName: %s\n", s[i].personName);
            printf("companyName: %s\n", s[i].companyName);
        }
    }
}
int addNameCard(NameCard *s, int size)
{
    int i,j, x;
    char *p, dump[20];
    if (size < 5)
    {
        printf("Enter nameCardID: \n");
        scanf("%d", &x);
        for(i=0; i<size; i++)
        {
            if(s[i].nameCardID == x)
            {
                printf("Enter personName: \n");
                scanf("\n");
                fgets(dump, 20, stdin);
                if(p=strchr(dump, '\n'))
                {
                    *p = '\0';
                }
                printf("Enter companyName: \n");
                fgets(dump, 20, stdin);
                if(p=strchr(dump, '\n'))
                {
                    *p = '\0';
                }
                printf("The nameCardID has already existed\n");
                return size;
            }
        }
        s[size].nameCardID = x;
        printf("Enter personName: \n");
        scanf("\n");
        fgets(s[size].personName, 20, stdin);
        if(p=strchr(s[size].personName, '\n'))
        {
            *p = '\0';
        }
        printf("Enter companyName: \n");
        fgets(s[size].companyName, 20, stdin);
        if(p=strchr(s[size].companyName, '\n'))
        {
            *p = '\0';
        }
        for(i=0; i<size; i++) //sorting
        {
            for(j=0; j<size-i; j++)
            {
                if(s[j].nameCardID > s[j+1].nameCardID)
                {
                    x = s[j].nameCardID;
                    s[j].nameCardID = s[j+1].nameCardID;
                    s[j+1].nameCardID = x;
                    strcpy(dump, s[j].personName);
                    strcpy(s[j].personName, s[j+1].personName);
                    strcpy(s[j+1].personName, dump);
                    strcpy(dump, s[j].companyName);
                    strcpy(s[j].companyName, s[j+1].companyName);
                    strcpy(s[j+1].companyName, dump);
                }
            }
        }
    }
    else if (size = 5)
    {
        printf("Enter nameCardID: \n");
        scanf("%d", &x);
        printf("Enter personName: \n");
        scanf("\n");
        fgets(dump, 20, stdin);
        if(p=strchr(dump, '\n'))
        {
            *p = '\0';
        }
        printf("Enter companyName: \n");
        fgets(dump, 20, stdin);
        if(p=strchr(dump, '\n'))
        {
            *p = '\0';
        }
        printf("The name card holder is full\n");
        return size;
    }
    printf("The name card has been added successfully\n");
    return size+1;
}
int removeNameCard(NameCard *s, int size, char *target)
{
    int i, j;
    char targetu[20], su[20];
    if (size == 0)
    {
        printf("The name card holder is empty\n");
        return size;
    }
    for(i=0; i<=strlen(target); i++)
    {
        targetu[i] = toupper(target[i]);
    }
    for(i=0; i<size; i++)
    {
        for(j=0; j<=strlen(s[i].personName); j++)
        {
            su[j]= toupper(s[i].personName[j]);

        }
        if(strcmp(su, targetu)==0)
        {
            printf("The name card is removed \n");
            printf("nameCardID: %d\n", s[i].nameCardID);
            printf("personName: %s\n", s[i].personName);
            printf("companyName: %s\n", s[i].companyName);
            for(i; i<(size-1); i++)
            {
                s[i].nameCardID = s[i+1].nameCardID;
                strcpy(s[i].personName, s[i+1].personName);
                strcpy(s[i].companyName, s[i+1].companyName);
            }
            return size-1;
        }
    }
    printf("The target person name is not in the name card holder\n");
    return size;


}
int getNameCard(NameCard *s, int size, char *target)
{
    int i, j;
    char targetu[20], su[20];
    for(i=0; i<=strlen(target); i++)
    {
        targetu[i] = toupper(target[i]);
    }
    for(i=0; i<size; i++)
    {
        for(j=0; j<=strlen(s[i].personName); j++)
        {
            su[j]= toupper(s[i].personName[j]);

        }
        if(strcmp(su, targetu)==0)
        {
            printf("The target person name is found \n");
            printf("nameCardID: %d\n", s[i].nameCardID);
            printf("personName: %s\n", s[i].personName);
            printf("companyName: %s\n", s[i].companyName);
            return 1;
        }
    }
    return 0;
}
