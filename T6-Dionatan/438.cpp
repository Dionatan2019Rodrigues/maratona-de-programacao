#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    const double PI = 3.141592653589793;
    double x1, y1, x2, y2, x3, y3, a, b, c, A, R;


    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {

        a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
        c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

        A = 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1);

        R = (a * b * c) / (4 * A) * 2 * PI;

        cout << fixed << setprecision(2) << R << endl;
    }

    return 0;
}