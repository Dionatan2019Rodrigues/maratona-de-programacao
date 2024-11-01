#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 
#include <iomanip>

using namespace std;

int main() {
    int casos = 1;

    while (true) {
        int C, S;
        cin >> C >> S;

        if (cin.fail()) {
            break;
        }

        vector<int> a(S);
        for (int i = 0; i < S; ++i) {
            cin >> a[i];
        }

        double y = accumulate(a.begin(), a.end(), 0.0) / C;

        while (a.size() < 2 * C) {
            a.push_back(0);
        }

        sort(a.begin(), a.end());

        double imbalance = 0.0;

        cout << "Set #" << casos << endl;
        casos++;

        for (int i = 0; i < C; ++i) {
            cout << setw(2) << i << ":";
            if (a[i] > 0) {
                cout << " " << a[i];
            }
            if (a[2 * C - 1 - i] > 0) {
                cout << " " << a[2 * C - 1 - i];
            }
            imbalance += abs(a[i] + a[2 * C - 1 - i] - y);
            cout << endl;
        }

        cout << fixed << setprecision(5) << "IMBALANCE = " << imbalance << endl << endl;

    }
    return 0;
}