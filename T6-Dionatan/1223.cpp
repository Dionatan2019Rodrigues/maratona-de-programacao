#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

#define MAX 1000

class Ponto {
public:
    double x, y;

    Ponto(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    Ponto operator+(const Ponto& outro) const {
        return {x + outro.x, y + outro.y};
    }

    Ponto operator-(const Ponto& outro) const {
        return {x - outro.x, y - outro.y};
    }

    Ponto operator*(double escalar) const {
        return {x * escalar, y * escalar};
    }

    double distanciaPara(const Ponto& outro) const {
        return sqrt((x - outro.x) * (x - outro.x) + (y - outro.y) * (y - outro.y));
    }
};

double distanciaEntreSegmentos(const Ponto& p, const Ponto& q, const Ponto& r) {
    double t = (r.x - p.x) * (q.x - p.x) + (r.y - p.y) * (q.y - p.y);
    t /= p.distanciaPara(q) * p.distanciaPara(q);
    t = max(0.0, min(1.0, t));
    Ponto projecao = p + (q - p) * t;
    return projecao.distanciaPara(r);
}

double distanciasMinimasEntreSegmentos(const Ponto& p1, const Ponto& p2, const Ponto& q1, const Ponto& q2) {
    return min({
        distanciaEntreSegmentos(p1, p2, q1),
        distanciaEntreSegmentos(p1, p2, q2),
        distanciaEntreSegmentos(q1, q2, p1),
        distanciaEntreSegmentos(q1, q2, p2)
    });
}

int main() {
    int N, k;
    double L, H, distanciaMinima;
    Ponto Pi[MAX], Pf[MAX];

    while (cin >> N) {
        distanciaMinima = numeric_limits<double>::max();
        cin >> L >> H;

        for (k = 0; k < N; ++k) {
            if (k % 2 == 0)
                Pi[k] = {0.0, 0.0};
            else
                Pi[k] = {L, 0.0};

            cin >> Pi[k].y >> Pf[k].x >> Pf[k].y;
        }

        for (k = 0; k < N; ++k) {
            if (k % 2 == 0) {
                distanciaMinima = min(distanciaMinima, distanciasMinimasEntreSegmentos({L, 0}, {L, H}, Pi[k], Pf[k]));
            } else {
                distanciaMinima = min(distanciaMinima, distanciasMinimasEntreSegmentos({0, 0}, {0, H}, Pi[k], Pf[k]));
            }
            if (k > 0) {
                distanciaMinima = min(distanciaMinima, distanciasMinimasEntreSegmentos(Pi[k], Pf[k], Pi[k - 1], Pf[k - 1]));
            }
        }

        cout << fixed << setprecision(2) << distanciaMinima << endl;
    }

    return 0;
}