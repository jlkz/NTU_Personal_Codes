#include "ClassA.h"
#include <iostream>
using namespace std;


void A::print(void) {
    cout << "A values: " << a << " " << b << "\n" ;
}

int A::doubleIt(A a) { return a.a * a.a ; }

A A::operator +(const A op){
    int resA = op.a + a;
    int resB = op.b + b;
    return(A(resA, resB));
}



