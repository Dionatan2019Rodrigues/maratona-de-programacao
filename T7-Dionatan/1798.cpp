#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    vector<int> c(N), v(N);
    for (int i = 0; i < N; ++i) {
        cin >> c[i] >> v[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(T + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= T; ++j) {
            if (j >= c[i - 1])
                dp[i][j] = max(dp[i - 1][j], dp[i][j - c[i - 1]] + v[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[N][T] << endl;

    return 0;
}