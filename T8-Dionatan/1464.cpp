#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Ponto {
    int x, y;
};

int produtoVetorial(const Ponto& a, const Ponto& b, const Ponto& c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool compararPontos(const Ponto& a, const Ponto& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

// Algoritmo de Graham Scan modificado
vector<Ponto> encontrarEnvoltorioConvexo(vector<Ponto>& pontos) {
    // Encontrar o ponto mais à esquerda
    int indicePontoMaisEsquerdo = 0;
    for (int i = 1; i < pontos.size(); ++i) {
        if (pontos[i].x < pontos[indicePontoMaisEsquerdo].x ||
            (pontos[i].x == pontos[indicePontoMaisEsquerdo].x && pontos[i].y < pontos[indicePontoMaisEsquerdo].y)) {
            indicePontoMaisEsquerdo = i;
        }
    }

    // Ordenar os pontos em relação ao ponto mais à esquerda, usando o produto vetorial
    swap(pontos[0], pontos[indicePontoMaisEsquerdo]);
    sort(pontos.begin() + 1, pontos.end(),
              [&pontos, indicePontoMaisEsquerdo](const Ponto& a, const Ponto& b) {
                  int orientacao = produtoVetorial(pontos[indicePontoMaisEsquerdo], a, b);
                  return orientacao > 0 || (orientacao == 0 &&
                                           (pontos[indicePontoMaisEsquerdo].x - a.x) * (pontos[indicePontoMaisEsquerdo].x - b.x) +
                                           (pontos[indicePontoMaisEsquerdo].y - a.y) * (pontos[indicePontoMaisEsquerdo].y - b.y) < 0);
              });

    // Construir o envoltório convexo usando uma pilha
    vector<Ponto> pilha;
    pilha.push_back(pontos[0]);
    pilha.push_back(pontos[1]);

    for (int i = 2; i < pontos.size(); ++i) {
        while (pilha.size() >= 2 && produtoVetorial(pilha[pilha.size() - 2], pilha[pilha.size() - 1], pontos[i]) <= 0) {
            pilha.pop_back();
        }
        pilha.push_back(pontos[i]);
    }

    return pilha;
}

//FIXME: Wrong answer (5%) at the beecrowd
int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<Ponto> pontos(n);
        for (int i = 0; i < n; ++i) {
            cin >> pontos[i].x >> pontos[i].y;
        }

        vector<Ponto> envoltorioConvexo = encontrarEnvoltorioConvexo(pontos);

        if (envoltorioConvexo.size() % 2 == 0) {
            cout << "Do not take this onion to the lab!" << endl;
        } else {
            cout << "Take this onion to the lab!" << endl;
        }
    }

    return 0;
}