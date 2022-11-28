#include "animal.h"
#include <iostream>
#include <string>
using namespace std ;

string colorString[5] = {"Green", "Blue", "White", "Black", "Brown"};

Animal::Animal() : _name("unknown") {
        cout << "constructing Animal object "<< _name << endl ;
}
Animal::Animal(string n, COLOR c): _name(n), _color(c){
    cout << "constructing Animal object parma "<< _name << " with color "<< colorString[c] <<endl;
}

Animal::~Animal() {
    cout << "destructing Animal object "<< _name << endl ;
}
void Animal::speak() {
    cout << "Animal speaks "<< endl ;
}

void Mammal::eat() const {
    cout << "Mammal eat " << endl ;
}
Mammal::Mammal(){};
Mammal::Mammal(string n, COLOR c){
    _name = n;
    _color = c;
     cout << "constructing mammal object parma "<< _name << " with color "<< colorString[c] <<endl;
 }
Mammal::~Mammal(){
    cout << "destructing Mammal object "<< endl ;
}

void Mammal::move() {
    cout<<"mammal move"<<endl;
}
void Mammal::speak(){
    cout << "Mammal speaks "<< endl ;
}
