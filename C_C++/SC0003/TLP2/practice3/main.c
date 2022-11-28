#include <stdio.h>
#include <stdlib.h>

int divide1(int m, int n, int *r);
void divide2(int m, int n, int *q, int *r);
int m, n, q, r;
int main()
{


   printf("Enter two numbers (m and n): \n");
   scanf("%d %d", &m, &n);
   q = divide1(m, n, &r);
   printf("divide1(): quotient %d remainder %d\n", q, r);
   divide2(m, n, &q, &r);
   printf("divide2(): quotient %d remainder %d\n", q, r);
   return 0;
}
int divide1(int m, int n, int *r)
{
   *r = m%n;
   return (m - *r)/n;
}
void divide2(int m, int n, int *q, int *r)
{
   *r = m%n;
   *q = (m - *r)/n;
}
