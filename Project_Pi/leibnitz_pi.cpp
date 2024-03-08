#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Leibnitz formula
    double Leibnitz;
    int n;
    int num;
    double sum = 0;

    cout << "Input a value for n: ";
    cin >> n;

    for (int k = 0; k < n; k++) { // Loops through n times
        num = pow(-1, k); // numerator
        // cout << "NUM: " << num << endl;
        Leibnitz = static_cast<double>(num) / (2 * k + 1); //numerator/demoninator and cast to double
        // cout << "LEIBNITZ: " << Leibnitz << endl;
        sum += Leibnitz; // Adds the current value to the total value
        // cout << "SUM: " << sum << endl;
    }


    cout.precision(15);
    cout << fixed;
    cout << "Approximation of Pi: " << 4 * sum << " : n = " << n << endl;
    cout << "Actual value of Pi: 3.141592653589793" << endl;
    


    return 0;
}
