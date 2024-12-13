#include <iostream>

using namespace std;

int calcularMDC(int a, int b) {
    while (a % b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return b;
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        int F1, F2;
        cin >> F1 >> F2;
        cout << calcularMDC(F1, F2) << endl;
    }

    return 0;
}