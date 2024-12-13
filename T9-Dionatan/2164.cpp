#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double fibonacci(int n) {
    return (pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n)) / sqrt(5);
}

int main() {
    int n;
    cin >> n;

    double resultado = fibonacci(n);
    cout << fixed << setprecision(1) << resultado << endl;

    return 0;
}