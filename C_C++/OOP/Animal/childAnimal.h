#ifndef CHILDANIMAL_H
#define CHILDANIMAL_H
#include "animal.h"

class Dog:public Mammal{
private:
    string _owner;
public:
    Dog(string n, COLOR c, string owner);
    ~Dog();
    void speak();
    void move();
};

class Cat:public Mammal{
public:
    Cat(string n, COLOR c);
    ~Cat();
    void speak();
    void move();
};

class Lion:public Mammal{
public:
    Lion(string n, COLOR c);
    ~Lion();
    void speak();
    void move();
};

#endif // CHILDANIMAL_H
