#include <iostream>
#include <string>
#include <vector>

// Interface representing the sound behavior
class SoundMaker {
public:
    virtual void makeSound() = 0;
    virtual ~SoundMaker() {}  // Ensure proper cleanup for derived classes
};

// Class representing animals
class Animal {
protected:
    std::string name;
    SoundMaker* soundMaker; // Composition: Animal has a SoundMaker
public:
    Animal(std::string name, SoundMaker* soundMaker) : name(name), soundMaker(soundMaker) {}
    void display() {
        std::cout << "Name: " << name << std::endl;
    }
    void makeSound() {
        soundMaker->makeSound();
    }
    virtual ~Animal() {}  // Ensure proper cleanup for derived classes
};

// Class representing dogs and their sound
class DogSound : public SoundMaker {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

// Class representing cats and their sound
class CatSound : public SoundMaker {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

// Class representing a Zoo
class Zoo {
private:
    std::vector<Animal*> animals; // Vector of pointers to animals
public:
    void addAnimal(Animal* animal) {
        animals.push_back(animal);
    }
    void makeSounds() {
        for (const auto& animal : animals) {
            animal->makeSound();
        }
    }
    ~Zoo() {
        // Cleanup memory
        for (const auto& animal : animals) {
            delete animal;
        }
    }
};

int main() {
    Zoo zoo;

    // Create dogs with DogSound
    Animal* dog1 = new Animal("Buddy", new DogSound());
    Animal* dog2 = new Animal("Max", new DogSound());

    // Create cats with CatSound
    Animal* cat1 = new Animal("Whiskers", new CatSound());
    Animal* cat2 = new Animal("Snowball", new CatSound());

    // Add animals to the zoo
    zoo.addAnimal(dog1);
    zoo.addAnimal(dog2);
    zoo.addAnimal(cat1);
    zoo.addAnimal(cat2);

    // Make sounds in the zoo
    zoo.makeSounds();

    return 0;
}
