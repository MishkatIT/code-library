#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> primes;

void sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int countDivisors(int x) {
    int temp = x, divisors = 1;
    for (int p : primes) {
        if (p * p > temp || temp == 1)
            break;
        int count = 0;
        while (temp % p == 0) {
            temp /= p;
            count++;
        }
        divisors *= (count + 1);
    }
    if (temp > 1)
        divisors *= 2;
    return divisors;
}

int32_t main() {
    int limit = sqrt(1e10) + 5;
    sieve(limit);

    int n;
    cout << "Enter a number: ";
    cin >> n;

    int numDivisors = countDivisors(n);

    cout << "Number of divisors of " << n << " is " << numDivisors << endl;

    return 0;
}

