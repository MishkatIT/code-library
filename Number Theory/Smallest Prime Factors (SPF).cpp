#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e5 + 10;

vector<ll> spf(N);

void sieve() {
    for (ll i = 2; i < N; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            for (ll j = 2 * i; j < N; j += i) {
                if (spf[j] == 0) {
                    spf[j] = i;
                }
            }
        }
    }
}

int main() {
    sieve();

    cout << "Smallest Prime Factors for numbers up to " << N - 1 << ":\n";
    for (ll i = 2; i < N; i++) {
        cout << "smallest prime factor of " << i << " is " << spf[i] << "\n";
    }

    return 0;
}
