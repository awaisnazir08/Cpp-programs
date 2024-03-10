#include <iostream>
using namespace std;
class Calculator {
private:
    int num1;
    int num2;

public:
    // constructor
    Calculator(int a, int b) : num1(a), num2(b) {}

    //getter functions to access the values of the private data members
    int getNum1() const {
        return num1;
    }

    int getNum2() const {
        return num2;
    }

    //setter functions to modify/set the values of the private data members
    void setNum1(int a) {
        num1 = a;
    }

    void setNum2(int b) {
        num2 = b;
    }

    //operations
    int add() const {
        return num1 + num2;
    }

    int subtract() const {
        return num1 - num2;
    }

    int multiply() const {
        return num1 * num2;
    }

    //division with zero exception handled
    double divide() const {
        if (num2 == 0) {
            cerr << "Error: Cannot divide by zero." << endl;
            return 0;
        }
        return static_cast<double>(num1) / num2;
    }
};

int main() {
    //creating an instance of the Calculator class
    Calculator myCalculator(10, 5);

    //accessing private members using getter functions
    cout << "Num1: " << myCalculator.getNum1() << endl;
    cout << "Num2: " << myCalculator.getNum2() << endl;

    //operations
    cout << "Addition: " << myCalculator.add() << endl;
    cout << "Subtraction: " << myCalculator.subtract() << endl;
    cout << "Multiplication: " << myCalculator.multiply() << endl;
    cout << "Division: " << myCalculator.divide() << endl;

    //accessing and modifying private data members using mutators
    myCalculator.setNum1(20);
    myCalculator.setNum2(4);

    //performing operations
    cout << "Modified Num1: " << myCalculator.getNum1() << endl;
    cout << "Modified Num2: " << myCalculator.getNum2() << endl;
    cout << "Modified Addition: " << myCalculator.add() << endl;
    cout << "Modified Subtraction: " << myCalculator.subtract() << endl;

    return 0;
}
