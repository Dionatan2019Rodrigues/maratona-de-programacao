#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double r, n, PI, angulo, anguloR, a, h, A;

    while (cin >> r >> n) {

        PI = 360.0 / n;
        angulo = 90.0 - (PI / 2.0);
        anguloR = angulo * M_PI / 180.0; // 

        a = 2 * r * cos(anguloR);
        h = r * sin(anguloR);
        A = ((a * h) / 2.0) * n;

        cout << fixed << setprecision(3) << A << endl;
    }

    return 0;
}