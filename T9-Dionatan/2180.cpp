#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= sqrt(n); ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

vector<int> primes_after(int n, int quantity = 10) {
    int limit = n + quantity * 50;
    vector<bool> is_prime = sieve(limit);

    vector<int> result;
    for (int i = n; i <= limit; ++i) {
        if (is_prime[i]) {
            result.push_back(i);
            if (result.size() == quantity) {
                break;
            }
        }
    }
    return result;
}

int main() {
    int number;
    cin >> number;

    vector<int> primes = primes_after(number);
    int sum_of_primes = 0;
    for (int prime : primes) {
        sum_of_primes += prime;
    }

    int hours = 60000000 / sum_of_primes;
    int days = hours / 24;

    cout << sum_of_primes << " km/h" << endl;
    cout << hours << " h / " << days << " d" << endl;
    return 0;
}