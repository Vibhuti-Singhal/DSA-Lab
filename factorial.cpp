#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1)
        return 1;           // base case
    return n * factorial(n - 1);
}
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (n < 0) {
        cout << "Factorial not defined for negative numbers.\n";
    }
    else {
        cout << "Factorial of " << n << " = " << factorial(n) << endl;
    }
    return 0;
}
