#include <stdio.h>
#include <stdlib.h>

int digitValue1(int num, int k);
void digitValue2(int num, int k, int *result);
int main()
{
   int num, digit, result=-1;

   printf("Enter the number: \n");
   scanf("%d", &num);
   printf("Enter k position: \n");
   scanf("%d", &digit);
   printf("digitValue1(): %d\n",  digitValue1(num, digit));
   digitValue2(num, digit, &result);
   printf("digitValue2(): %d\n", result);
   return 0;
}
int digitValue1(int num, int k)
{
    int count, r;
    for(count=1; count<=k; count++)
    {
        r=num%10;
        num = num/10;
    }
    return r;
}
void digitValue2(int num, int k, int *result)
{
   int count;
    for(count=1; count<=k; count++)
    {
        *result=num%10;
        num = num/10;
    }

}
