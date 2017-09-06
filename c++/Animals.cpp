#include <iostream>
#include <string>
#include <map>
#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include <utility> 


using namespace std;

class Animal {
    protected:
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
            cout << "name: "     << Animal::name    << endl
                 << "age: "      << Animal::age     << endl
                 << "type: "     << Animal::type    << endl
                 << "color: "    << Animal::color   << endl
                 << "gender: "   << Animal::gender  << endl
                 << "height: "   << Animal::height  << endl
                 << "weight: "   << Animal::weight  << endl
                 << "note: "     << Animal::note    << endl;
        }
        string language(){
            if (Animal::type == "DOG")
                return "Barkkkkkk ROOOOWWOOF";
            
            else if (Animal::type == "CAT")
                return "Mew MEOWW";
            
            else 
                return "Alien Noises";
        }
        Animal(){
            srand(time(NULL));
            color = "red";
            age = rand() % 100;
            type = "DOG";
            weight = rand() % 100;
            height = rand() % 100;     
            gender = "Male";
            name = "Doge";
            note = "";
        }
};

class Dog: public Animal {
    private:
        string type;
        string voice;
    public:
         Dog(){
            srand(time(NULL));
            color = "red";
            age = rand() % 100;
            type = "DOG";
            weight = rand() % 100;
            height = rand() % 100;     
            gender = "Male";
            name = "Doge";
            note = "";
        }
};

class Cat: public Animal {
    private:
        string type;
        string voice;
    public:
        Cat(){
            srand(time(NULL));
            color = "red";
            age = rand() % 100;
            type = "CAT";
            weight = rand() % 100;
            height = rand() % 100;     
            gender = "Female";
            name = "Meowgi";
            note = "";
        }
};

int main() {
    srand(time(NULL));

    map<string, Animal> Animals;
    vector<string> types;
    vector<string> names;
    vector<string> pets; 
    ifstream nameFile;
    ifstream typesFile;
    string firstPetName;
    string typeInput;
    string line;
    char userInput = 'a';

    nameFile.open("../names.txt");
    while (getline (nameFile, line))
        names.push_back (line);
    
    typesFile.open("../types.txt");
    while (getline (typesFile, line))
        types.push_back (line);
    
    cout << "Welcome to the House Animal Arena! \n"
         << "You can generate animals and battle them \n"
         << "To begin type the name of your first pet\n";
    cin >> firstPetName;
    cout << "What animal type\n(d) for Dog\n(c) for cat\nType anything to generate a new type\n";
    cin >> typeInput;
    
    if (typeInput == "d" || typeInput == "D") typeInput = "DOG";
    else if (typeInput == "c" || typeInput == "C") typeInput = "CAT";
    else typeInput = types[rand() % 379 +1];

    cout << "Generating new " << typeInput << endl << endl;
    Animal firstA;
    Animals.insert(make_pair(firstPetName, firstA));
    Animals[firstPetName].setName(firstPetName);
    Animals[firstPetName].setType(typeInput);
    Animals[firstPetName].print();
    cout << endl << endl;
    do {

        cout << "You have a total of " << Animals.size() << " in your arena \n"
             << "Here are your options\n"
             << "(g) generate new randopm pet\n"
             << "(a) add new animal\n"
             << "(e) edit pets\n"
             << "(q) to quit the program\n";
        cin >> userInput;

        switch (userInput) {
            default: cout << "Command not recognized \n";
            case 'g': {
                string name = names[rand() % 247 +1];
                Animal newA;
                Animals.insert(make_pair(name, firstA));
                Animals[firstPetName].setName(name);
                Animals[firstPetName].setType(types[rand() % 379 +1]);
                Animals[firstPetName].print();
                cout << name << " has been generated \n\n";
                break;
            }
            case 'a': {
                string newPet;
                string newType;
                cout << "To begin type the name of your first pet\n";
                cin >> newPet;
                cout << "What animal type\n(d) for Dog\n(c) for cat\nType anything to generate a new type\n";
                cin >> newType;
                
                if (newType == "d" || newType == "D") newType = "DOG";
                else if (newType == "c" || newType == "C") newType = "CAT";
                else newType = types[rand() % 379 +1];

                cout << "Generating new " << newType << endl << endl;
                Animal firstA;
                Animals.insert(make_pair(newPet, firstA));
                Animals[firstPetName].setName(newPet);
                Animals[firstPetName].setType(newType);
                Animals[firstPetName].print();
                cout << "New Animal Created\nReturning\n" << endl;
                break;
            }
            case 'e': {
                string iName;
                char option;
                cout << "Enter pet name\n";
                cin >> iName;
                cout << "Enter action to change \n"
                     << "\n"
                     <<"A age\n"
                     <<"W weight\n"
                     <<"H height\n"
                     <<"T type\n"
                     <<"N name\n"
                     <<"C color\n"
                     <<"G gender\n\n";
                cin >> option;
                switch(option) {
                    case 'a' :  {
                        int i;
                        cout << "Input new age\n";
                        cin >> i;
                        Animals[iName].setAge(i);
                        cout << "Changes saved!\n";
                        Animals[iName].print();
                        break;
                    }   
                    case 'w' :  {
                        double i;
                        cout << "Input new weight\n";
                        cin >> i;
                        Animals[iName].setWeight(i);
                        cout << "Changes saved!\n";
                        Animals[iName].print();
                        break;
                    }   
                    case 'h' :  {
                        double i;
                        cout << "Input new height\n";
                        cin >> i;
                        Animals[iName].setHeight(i);
                        break;
                    }   
                    case 't' :  {
                        string i;
                        cout << "Input new type\n";
                        cin >> i;
                        Animals[iName].setType(i);
                        cout << "Changes saved!\n";
                        Animals[iName].print();
                        break;
                    }   
                    case 'n' :  {
                        string i;
                        cout << "Input new name\n";
                        cin >> i;
                        Animals[iName].setName(i);
                        cout << "Changes saved!\n";
                        Animals[iName].print();
                        break;
                    }
                    case 'c' :  {
                        string i;
                        cout << "Input new color\n";
                        cin >> i;
                        Animals[iName].setColor(i);
                        cout << "Changes saved!\n";
                        Animals[iName].print();
                        break;
                    }
                    case 'g' :  {
                        string i;
                        cout << "Input new gender\n";
                        cin >> i;
                        Animals[iName].setGender(i);
                        cout << "Changes saved!\n";
                        Animals[iName].print();
                        break;
                    }
                    default : cout << "Command not valid, returning" << endl;
                }
            }
        }
        cout << "Enter any key to continue.\nEnter (q) to quit\n";
        cin >> userInput;
    } while (userInput != 'q');
    
    return 0;
}