#include "animal.h"
#include "childAnimal.h"
#include <iostream>
#include <string>
using namespace std ;

string colorString[5] = {"Green", "Blue", "White", "Black", "Brown"};

int main() {
    //Animal a("dog", Black);
    /*Animal* ptr = new Mammal("monkey", Brown);
    ptr->speak() ;
    Dog d("dog", Blue, "Jerick");
    d.speak();
    d.move();
    Dog dogi("Lassie", White, "Andy");
    Mammal *aniPtr = &dogi ;
    Mammal &aniRef = dogi ;
    Mammal aniVal = dogi ;
    aniPtr->speak() ;
    aniRef.speak() ;
    aniVal.speak() ;*/

    Mammal* zoo[3] ;
    int i  = 0, choice = 0, color;
    string name;
    COLOR colorENUM;

    do{
        cout<<"Select the animal to send to Zoo"<<endl;
        cout<<"(1) Dog (2) Cat (3) Lion (4) Move all animals (5) Quit"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
            {
                cout<<"Enter name:"<<endl;
                cin>>name;
                cout<<"Enter color:"<<endl;
                cin>>color;
                COLOR colorENUM = static_cast<COLOR>(color);
                if(i!=3){
                    Mammal* ptr = new Dog(name, colorENUM, "Jerick");
                    zoo[i++] = ptr;
                }
                break;
            }
            case 2:
            {
                cout<<"Enter name:"<<endl;
                cin>>name;
                cout<<"Enter color:"<<endl;
                cin>>color;
                COLOR colorENUM = static_cast<COLOR>(color);
                if(i!=3){
                    Mammal* ptr = new Cat(name, colorENUM);
                    zoo[i++] = ptr;
                }
                break;
            }

            case 3:
            {

                cout<<"Enter name:"<<endl;
                cin>>name;
                cout<<"Enter color:"<<endl;
                cin>>color;
                COLOR colorENUM = static_cast<COLOR>(color);
                if(i!=3){
                    Mammal* ptr = new Lion(name, colorENUM);
                    zoo[i++] = ptr;
                }
                break;
            }
            case 4:
            {
                for(int j=0; j<i; j++){
                    zoo[j]->move();
                    zoo[j]->speak();
                    zoo[j]->eat();
                }
            }
        }

    }while(choice!=5);

    cout << "Program exiting … "<< endl ;
    return 0;
}
