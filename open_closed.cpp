#include <iostream>
#include <string>
using namespace std;
// PlayerRole class with a virtual method getRole()
class PlayerRole {
public:
    virtual string getRole() const = 0;
};

// Subclasses for different roles extend the PlayerRole class
class GoalkeeperRole : public PlayerRole {
public:
    string getRole() const override {
        return "goalkeeper";
    }
};

class DefenderRole : public PlayerRole {
public:
    string getRole() const override {
        return "defender";
    }
};

class MidfieldRole : public PlayerRole {
public:
    string getRole() const override {
        return "midfielder";
    }
};

class ForwardRole : public PlayerRole {
public:
    string getRole() const override {
        return "forward";
    }
};

class Footballer {
public:
    Footballer(const string& name, int age, const PlayerRole* role)
        : name(name), age(age), role(role) {}

    string getRole() const {
        return role->getRole();
    }

    string getName() const {
        return name;
    }

private:
    string name;
    int age;
    const PlayerRole* role;
};

int main() {
    ForwardRole forwardRole;
    Footballer hazard("Hazard", 32, &forwardRole);
    cout << hazard.getName() << " plays in the " << hazard.getRole() << " line" << endl;

    MidfieldRole midfieldRole;
    Footballer kante("Ngolo Kante", 31, &midfieldRole);
    cout << kante.getName() << " is the best " << kante.getRole() << " in the team!" << endl;

    return 0;
}
