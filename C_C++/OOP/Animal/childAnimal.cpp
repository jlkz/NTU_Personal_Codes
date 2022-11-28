#include "animal.h"
#include "childAnimal.h"
#include <iostream>
#include <string>
using namespace std;

string colorString[5] = {"Green", "Blue", "White", "Black", "Brown"};

Dog::Dog(string n, COLOR c, string owner): Mammal(n, c), _owner(owner){
    cout << "constructing dog object "<< _name << " with color "<< colorString[c]
    << " owner: "<<_owner<< endl;
}

Dog::~Dog(){
    cout<<"destructing dog object"<< endl;
}
void Dog::speak(){
    cout<<"Woof"<<endl;
}
void Dog::move(){
    cout<<"run"<<endl;
}

Cat::Cat(string n, COLOR c): Mammal(n, c){}
Cat::~Cat(){
    cout<<"destructing cat"<<endl;
}

void Cat::speak(){
    cout<<"meow"<<endl;
}

void Cat::move(){
    cout<<"prowl"<<endl;
}

Lion::Lion(string n, COLOR c): Mammal(n,c){}
Lion::~Lion(){
    cout<<"destructing Lion"<<endl;
}

void Lion::speak(){
    cout<<"roar"<<endl;
}

void Lion::move(){
    cout<<"leap far"<<endl;
}
