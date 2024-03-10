#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base class representing animals
class Animal
{
protected:
    string name;
    string getName() const {
        return name;
    }
public:
    Animal(string name) : name(name) {}
    virtual void makeSound() = 0;
    void display()
    {
        cout << "Name: " << name << endl;
    }
    virtual ~Animal() {}

};

// Derived class representing dogs
class Dog : public Animal
{
public:
    Dog(string name) : Animal(name) {}
    void makeSound() override
    {
        cout << name << " says Woof!" << endl;
    }
};

// Derived class representing cats
class Cat : public Animal
{
public:
    Cat(string name) : Animal(name) {}
    void makeSound() override
    {
        cout << name << " says Meow!" << endl;
    }
};

// Class representing a Zoo
class Zoo
{
public:
    vector<Animal *> animals; // Dynamic container for animals

    // Function to add an animal to the zoo
    void addAnimal(Animal *animal)
    {
        animals.push_back(animal);
    }
};

class AnimalSounds
{
public:
    void makeSounds(const Zoo* z)
    {
        for (auto &animal : z->animals)
        {
            animal->makeSound();
        }
    }
};

int main()
{
    Zoo zoo;
    AnimalSounds s;
    Dog dog1("Buddy");
    Dog dog2("Max");
    Cat cat1("Whiskers");
    Cat cat2("Snowball");
    zoo.addAnimal(&dog1);
    zoo.addAnimal(&dog2);
    zoo.addAnimal(&cat1);
    zoo.addAnimal(&cat2);
    s.makeSounds(&zoo);
    return 0;
}
