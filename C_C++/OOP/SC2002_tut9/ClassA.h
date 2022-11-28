#ifndef CLASSA_H
#define CLASSA_H

class A {
    protected :
        int a,b;
    public :
        A(int x =0, int y =0) {
            a = x ;
            b = y ;
        }
        virtual void print() ;
        int doubleIt(A a);
        A operator+(const A op);
};
#endif // CLASSA_h
