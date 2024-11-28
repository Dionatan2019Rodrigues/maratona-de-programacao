#include <iostream>
#include <cmath>

using namespace std;

bool eh_soma_de_dois_quadrados(int n) {
    // Caso base: números negativos não podem ser representados
    if (n < 0) {
        return false;
    }

    // Caso base: 0 e 1 podem ser representados
    if (n == 0 || n == 1) {
        return true;
    }

    // Fatorar n em primos
    int i = 2;
    while (i * i <= n) {
        int count = 0;
        while (n % i == 0) {
            count++;
            n /= i;
        }

        // Se um primo da forma 4k + 3 aparece com expoente ímpar, não é possível
        if (i % 4 == 3 && count % 2 != 0) {
            return false;
        }
        i++;
    }

    // Se n restou 1, então n é um quadrado perfeito
    if (n > 1 && n % 4 == 3) {
        return false;
    }

    return true;
}

int main() {
    int num;
    while (cin >> num) {
        if (eh_soma_de_dois_quadrados(num))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
    }
    return 0;
}