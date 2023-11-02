#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

void countPrimeFactors(int x) {
    for (int p = 2; p * p <= x; p++) {
        while (x % p == 0) {
            primes.push_back(p);
            x /= p;
        }
    }
    if (x > 1) {
        primes.push_back(x);
    }
}

int countDivisors(int x) {
    primes.clear(); // Clear the vector before each use.
    countPrimeFactors(x);

    int numDivisors = 1;
    int cnt = 1;
    for (int i = 1; i < primes.size(); i++) {
        if (primes[i] == primes[i - 1]) {
            cnt++;
        } else {
            numDivisors *= (cnt + 1);
            cnt = 1;
        }
    }
    numDivisors *= (cnt + 1);

    return numDivisors;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int numDivisors = countDivisors(n);

    cout << "Number of divisors of " << n << " is " << numDivisors << endl;

    return 0;
}
