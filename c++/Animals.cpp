#include <iostream>
#include <string>
#include <map>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

using namespace std;

class Animal {
    private:
        int age;
        
        double weight;
        double height;

        string gender;        
        string color;
        string type;
        string name;
        string note;
        
    public:
        void setAge     (int a)    { Animal::age    = a; }
        void setWeight  (double w) { Animal::weight = w; }
        void setHeight  (double h) { Animal::height = h; }
        void setType    (string t) { Animal::type   = t; }
        void setName    (string n) { Animal::name   = n; }
        void setColor   (string c) { Animal::color  = c; }
        void setGender  (string g) { Animal::gender = g; }
        void setNote    (string n) { Animal::note   = n; }

        int getAge        (){ return Animal::age; }
        double getWeight  (){ return Animal::weight; }
        double getHeight  (){ return Animal::height; }
        string getType    (){ return Animal::type; }
        string getName    (){ return Animal::name; }
        string getColor   (){ return Animal::color; }
        string getNote    (){ return Animal::note; }
        string getGender  (){ return Animal::gender; }
        void print(){
            cout << Animal::name    << endl
                 << Animal::age     << endl
                 << Animal::type    << endl
                 << Animal::color   << endl
                 << Animal::gender  << endl
                 << Animal::height  << endl
                 << Animal::weight  << endl
                 << Animal::note    << endl;
        }
        string language(){
            if (Animal::type == "DOG"){
                return "Barkkkkkk ROOOOWWOOF";
            }
            else if (Animal::type == "CAT"){
                return "Mew MEOWW";
            }
            else {
                return "Alien Noises";
            }
        }
        Animal(){
            srand(time(NULL));
            color = "red";
            age = rand() % 100;
            weight = rand() % 100;
            height = rand() % 100;     
            gender = "Male";
            type = "DOG"; 
            name = "Doge";
            note = "He's a murderer";
        }
};

int main() {
    Animal Dog;
    //Dog.print();
    cout << "Speak!"<< endl << Dog.language() << endl;
    Animal * Cat = new Animal;
    //Cat -> print();
    return 0;
}