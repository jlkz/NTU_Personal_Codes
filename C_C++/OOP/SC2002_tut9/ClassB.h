#ifndef CLASSB_H
#define CLASSB_H

#include "ClassA.h"

class B: public A {
    private:
        float p,q ;
    public :
        B(int m, int n, float u, float v) {
            p = u ;
            q = v ;
        }
        B() { p = q = 0 ; }
        void input(float u, float v) ;
        virtual void print(float) ;
};
#endif // CLASSB_H

