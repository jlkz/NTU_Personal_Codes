#include "ClassB.h"
#include <iostream>
using namespace std;

void B::print(float) {
    cout << "B values : " << p << " " << q << "\n" ;
}
void B::input(float x, float y) {
    p = x ; q = y ;
}
