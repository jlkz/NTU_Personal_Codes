#include <iostream>
#include "ClassA.h"
#include "ClassB.h"
using namespace std;



int main()
{
    A a1(10,20), a2(3, 1), a3, *ptr;
    B b1;
    b1.input(7.5, 3.142) ;
    ptr = &a1 ;
    ptr->print() ;
    ptr = &b1;
    ptr->print() ;
    a3 = a1.operator+(a1);
    ptr = &a3;
    ptr->print();
    return 0;
}
