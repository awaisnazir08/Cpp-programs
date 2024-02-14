#include <iostream>
#include <vector>

// Observer base class
class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

// Concrete Observer class
class ConcreteObserver : public Observer {
public:
    ConcreteObserver(const std::string& name) : name(name) {}

    void update(const std::string& message) override {
        std::cout << "Observer " << name << " received update: " << message << std::endl;
    }

private:
    std::string name;
};

// Subject class
class Subject {
public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        // Remove observer from the list
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers(const std::string& message) {
        for (auto observer : observers) {
            observer->update(message);
        }
    }

private:
    std::vector<Observer*> observers;
};

int main() {
    // Create subject
    Subject subject;

    // Create observers
    ConcreteObserver observer1("Observer1");
    ConcreteObserver observer2("Observer2");

    // Register observers with the subject
    subject.addObserver(&observer1);
    subject.addObserver(&observer2);

    // Notify observers of a change in state
    subject.notifyObservers("State change!");

    // Unregister an observer
    subject.removeObserver(&observer1);

    // Notify remaining observers
    subject.notifyObservers("Another state change.");

    return 0;
}
