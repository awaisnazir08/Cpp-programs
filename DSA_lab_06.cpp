#include <iostream>
#include <ctime>
using namespace std;

class Timer {
public:
    Timer() {
        start_time = clock();
    }

    double elapsed() {
        clock_t end_time = clock();
        return double(end_time - start_time) / CLOCKS_PER_SEC;
    }

private:
    clock_t start_time;
};

// Recursive function to calculate Fibonacci
int recursiveFibonacci(int n) {
    if (n <= 1)
        return n;
    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

// Iterative function to calculate Fibonacci
int iterativeFibonacci(int n) {
    if (n <= 1)
        return n;

    int a = 0, b = 1, result;
    for (int i = 2; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter a number (n) for Fibonacci: ";
    cin >> n;

    Timer recursiveTimer;
    int recursiveResult = recursiveFibonacci(n);
    double recursiveTime = recursiveTimer.elapsed();

    Timer iterativeTimer;
    int iterativeResult = iterativeFibonacci(n);
    double iterativeTime = iterativeTimer.elapsed();

    cout << "Recursive Fibonacci: " << recursiveResult << ", Time: " << recursiveTime << " seconds" << endl;
    cout << "Iterative Fibonacci: " << iterativeResult << ", Time: " << iterativeTime << " seconds" << endl;

    return 0;
}
