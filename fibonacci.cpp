#include <iostream> 
using namespace std;


int fibonacci(int n) {
    if (n == 0 || n == 1)              // Base case: return n if it is 0 or 1
       return n;
    else 
        return fibonacci(n - 1) + fibonacci(n - 2) ; 
}
int main() { 
    int n; 
    cout << "Enter the number of terms: "; 
    cin >> n; 
    cout << "Fibonacci Series up to " << n << " terms: "; 
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << "  " ; 
    }
    cout << endl; 
    return 0;
}
