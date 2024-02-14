#include <bits/stdc++.h>
using namespace std;
const int N = 2e6;


vector<int>prime;
vector<bool> isPrime(N, true);
void sieve() {
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            prime.push_back(i);
        }
    }
}



int main() {
    sieve();
    return 0;
}
