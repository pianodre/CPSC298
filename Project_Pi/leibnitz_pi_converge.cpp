#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Leibnitz formula
    double Leibnitz;
    int n = 2;
    int num;
    double sum = 0;

    while (n <= 1048576) {
        sum = 0;  // Reset sum for each iteration of the outer loop

        for (int k = 0; k < n; k++) { // Loops through n times
            num = pow(-1, k); // numerator
            Leibnitz = static_cast<double>(num) / (2 * k + 1); // numerator/denominator and cast to double
            sum += Leibnitz; // Adds the current value to the total value
        }

        cout.precision(15);
        cout << fixed;
        cout << "PI: " << 4 * sum << "; n = " << n << endl;
        n *= 2;
    }

    return 0;
}
