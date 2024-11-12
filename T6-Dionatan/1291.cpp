#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    const double pi = acos(-1.0);
    double l, l2, area, areaQuadrado, areaListrada, areaPontos;

    for (string line; getline(cin, line);) {
        l = stod(line);
        l2 = l * l;

        area = l2 * (pi / 2 - 1);
        areaQuadrado = 4 * l2 * (1 - pi / 6 - sqrt(3) / 4);
        areaListrada = areaQuadrado + 2 * area - l2;
        areaPontos = 2 * area - 2 * areaListrada;

        cout << fixed << setprecision(3) << areaListrada << " " << areaPontos << " " << areaQuadrado << endl;
    }

    return 0;
}