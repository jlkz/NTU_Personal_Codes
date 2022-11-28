#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
using namespace std ;

enum COLOR { Green, Blue, White, Black, Brown } ;

class Animal{
public:
    Animal();
    Animal(string n, COLOR c);
    ~Animal();
    virtual void speak();
    virtual void move()=0;
protected:
    string _name;
    COLOR _color;
};

class Mammal:public Animal{
public:
    Mammal();
    Mammal(string n, COLOR c);
    ~Mammal();
    void move();
    void speak();
    void eat() const;

};

#endif // ANIMAL_H

