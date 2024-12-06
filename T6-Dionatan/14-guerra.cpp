#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//FIXME: encontrar erro, roda no caso de teste mas não passa no programmins figth
int main() {
    double d1, d2, d3, d4, media;

    while (true) {
        vector<double> x(3), y(3), z(3), w(3);

        for (int i = 0; i < 3; ++i) {
            cin >> x[i];
        }

        if (x[0] == 0 && x[1] == 0 && x[2] == 0) {
            break;
        }

        for (int i = 0; i < 3; ++i) {
            cin >> y[i] >> z[i] >> w[i];
        }

        d1 = sqrt((x[0] * x[0]) + (x[1] * x[1]) + (x[2] * x[2]));
        d2 = sqrt((y[0] * y[0]) + (y[1] * y[1]) + (y[2] * y[2]));
        d3 = sqrt((z[0] * z[0]) + (z[1] * z[1]) + (z[2] * z[2]));
        d4 = sqrt((w[0] * w[0]) + (w[1] * w[1]) + (w[2] * w[2]));

        media = (d1 + d2 + d3 + d4) / 4;

        if (abs(d1 - media) > 0.01 * media) {
            cout << "1" << endl;
        }else if (abs(d2 - media) > 0.01 * media) {
            cout << "2" << endl;
        }else if (abs(d3 - media) > 0.01 * media) {
            cout << "3" << endl;
        }else if (abs(d4 - media) > 0.01 * media) {
            cout << "4" << endl;
        }
    }

    return 0;
}