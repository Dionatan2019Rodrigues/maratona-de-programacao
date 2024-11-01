#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int S;
    cin >> S;

    vector<int> Q(S);
    vector<int> N(S);

    for (int i = 0; i < S; ++i) {
        cin >> Q[i];
    }

    for (int i = 0; i < S; ++i) {
        cin >> N[i];
    }

    sort(Q.begin(), Q.end());
    sort(N.begin(), N.end());

    int vitorias = 0;
    int i = 0, j = 0;

    while (i < S && j < S) {
        if (N[j] > Q[i]) {
            vitorias++;
            i++;
        }
        j++;
    }

    cout << vitorias << endl;

    return 0;
}