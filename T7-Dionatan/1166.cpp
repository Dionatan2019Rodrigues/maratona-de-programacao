#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool QuadradoPerfeito(int numero) {
    int raizQuadrada = sqrt(numero);
    return (raizQuadrada * raizQuadrada == numero);
}

int maxBolas(int N) {
    const int MAX_ITERACOES = 10000;

    vector<vector<int>> hastes(N);
    int bola = 1;
    int contador = 0;

    while (bola <= MAX_ITERACOES) {
        bool colocada = false;
        for (int i = 0; i < N && !colocada; ++i) {
            if (hastes[i].empty() || QuadradoPerfeito(hastes[i].back() + bola)) {
                hastes[i].push_back(bola);
                colocada = true;
                contador++;
            }
        }
        if (!colocada) {
            break;
        }
        bola++;
    }

    return contador;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        cout << maxBolas(N) << endl;
    }

    return 0;
}