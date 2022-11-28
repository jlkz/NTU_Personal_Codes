#include <stdio.h>
#include <stdlib.h>

int main()
{
    int grade, s, m;
    printf("enter salary:\n");
    scanf("%d", &s);
    printf("Enter merit:\n");
    scanf("%d", &m);

    if(s >= 500 && s <= 649){
        grade = 'c';}
    else if (s>=600 && s<=799){
        grade = 'b';
    }else if (s >= 700 && s<=899){
        grade = 'a';
    }
    if(s >= 600 && s <=649 && m>=10){
        grade = 'b';
    }else if (s >= 700 && s<=799 && m>=20){
        grade = 'a';
    }
    printf("The grade: %c", grade);

    return 0;
}
