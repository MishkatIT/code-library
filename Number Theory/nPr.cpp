#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1e9 + 7;
const int maxN = 1e5 + 10;

void modNormalize(ll &x) { x %= mod; if (x < 0) x += mod; }

ll modMultiply(ll x, ll y) { x %= mod, y %= mod; modNormalize(x), modNormalize(y); return (x * y) % mod; }
ll modPower(ll base, ll exponent) { ll result = 1; while (exponent > 0) { if (exponent & 1) result = modMultiply(result, base); base = modMultiply(base, base); exponent >>= 1; } return result; }
ll modInverse(ll x) { return modPower(x, mod - 2); }  // if mod is prime.

ll fact[maxN + 1];

void initFact() {
    fact[0] = 1;
    for (int i = 1; i <= maxN; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll nPr(int n, int r) {
    if (r > n) return 0;
    ll numerator = fact[n];
    ll denominator = fact[n - r];
    return modMultiply(numerator, modInverse(denominator));
}

int main() {
    initFact();
    ll n, r;
    cout << "Enter n and r: ";
    cin >> n >> r;
    ll result = nPr(n, r);
    cout << "P(" << n << ", " << r << ") mod " << mod << " = " << result << endl;
    return 0;
}

