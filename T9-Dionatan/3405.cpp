#include <iostream>

using namespace std;

int maxPowerOfFive(int n) {
    int count = 0;
    while (n % 5 == 0) {
        count++;
        n /= 5;
    }
    return count;
}

int countTrailingZeros(int n) {
    int zeros = 0;
    for (int i = 5; i <= n; i += 5) {
        zeros += maxPowerOfFive(i);
    }
    return zeros;
}

int main() {
    int N;
    while (cin >> N) {
        cout << countTrailingZeros(N) << endl;
    }
    return 0;
}