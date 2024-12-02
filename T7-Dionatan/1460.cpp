#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N, M, Q, L, U;

    while (true) {
        cin >> N >> M;

        if (N == 0 && M == 0) 
            break;

        vector<vector<int>> H(N, vector<int>(M));
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                cin >> H[i][j];
            }
        }

        cin >> Q;
        while (Q--) {
            cin >> L >> U;

            int maiorQd = 0;

            for (int i=0; i<N; i++) {
                auto init = lower_bound(H[i].begin(), H[i].end(), L);
                int colInicio = init-H[i].begin();

                for (int tam=maiorQd; tam<N-i && tam<M; tam++) {
                    if (i+tam >= N || colInicio+tam >= M) 
                        break;

                    if (H[i+tam][colInicio+tam]>U) 
                        break;

                    maiorQd = tam+1;
                }
            }

            cout << maiorQd << endl;
        }

        cout << "-" << endl;
    }

    return 0;
}