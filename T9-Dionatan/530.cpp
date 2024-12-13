#include <iostream>

using namespace std;

long long calcularCombinacao(int n, int k) {
    long long resultado = 1;

    if (k > n / 2) {
        k = n - k;
    }
    for (int i = 1; i <= k; ++i) {
        resultado *= (n - i + 1);
        resultado /= i;
    }
    return resultado;
}

int main() {
    int n, k;
    while (cin >> n >> k, n || k) {
        cout << calcularCombinacao(n, k) << endl;
    }
    return 0;
}