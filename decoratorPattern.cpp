#include <iostream>
#include <memory>

// Component interface
class Coffee {
public:
    virtual ~Coffee() = default;
    virtual void brew() const = 0;
};

// Concrete component
class SimpleCoffee : public Coffee {
public:
    void brew() const override {
        std::cout << "Brewing simple coffee" << std::endl;
    }
};

// Decorator base class
class CoffeeDecorator : public Coffee {
protected:
    std::shared_ptr<Coffee> coffee;

public:
    CoffeeDecorator(std::shared_ptr<Coffee> coffee) : coffee(coffee) {}
    void brew() const override {
        coffee->brew();
    }
};

// Concrete decorator 1
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(coffee) {}
    void addMilk() const {
        std::cout << "Adding milk" << std::endl;
    }
    void brew() const override {
        CoffeeDecorator::brew();
        addMilk();
    }
};

// Concrete decorator 2
class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(coffee) {}
    void addSugar() const {
        std::cout << "Adding sugar" << std::endl;
    }
    void brew() const override {
        CoffeeDecorator::brew();
        addSugar();
    }
};

int main() {
    // Create a simple coffee
    std::shared_ptr<Coffee> simpleCoffee = std::make_shared<SimpleCoffee>();

    // Decorate the simple coffee with milk
    std::shared_ptr<Coffee> milkCoffee = std::make_shared<MilkDecorator>(simpleCoffee);

    // Decorate the milk coffee with sugar
    std::shared_ptr<Coffee> sweetCoffee = std::make_shared<SugarDecorator>(milkCoffee);

    // Brew the final decorated coffee
    sweetCoffee->brew();

    return 0;
}
