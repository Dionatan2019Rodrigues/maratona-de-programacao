#include <iostream>
#include <vector>

using namespace std;

vector<int> fibo(int n) {
    vector<int> fib(n + 1, 0);
    fib[1] = 1;
    fib[2] = 2;

    for (int i = 3; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib;
}

int main() {
    vector<int> fib = fibo(45);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;

        int j = 45;
        int resposta = 0;
        while (j > 1) {
            if (fib[j] <= m) {
                m -= fib[j];
                resposta += fib[j - 1];
            }
            j--;
        }

        cout << resposta << endl;
    }

    return 0;
}