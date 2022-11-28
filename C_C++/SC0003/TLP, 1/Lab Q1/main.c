#include <stdio.h>
#include <stdlib.h>

int main()
{
    int student_number = 0, mark;
    printf("Enter Student ID: \n");
    scanf("%d", &student_number);
    while (student_number != -1)
    {
        printf("Enter mark: \n");
        scanf("%d", &mark);
        switch(mark/5)
        {
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
            printf("Grade = A\n");
            printf("Enter Student ID: \n");
            scanf("%d", &student_number);
            continue;
        case 14:
        case 13:
            printf("Grade = B\n");
            printf("Enter Student ID: \n");
            scanf("%d", &student_number);
            continue;
        case 12:
        case 11:
            printf("Grade = C\n");
            printf("Enter Student ID: \n");
            scanf("%d", &student_number);
            continue;
        case 10:
        case 9:
            printf("Grade = D\n");
            printf("Enter Student ID: \n");
            scanf("%d", &student_number);
            continue;
        default:
            printf("Grade = F\n");
            printf("Enter Student ID: \n");
            scanf("%d", &student_number);
            continue;
        }


    }

    return 0;
}


