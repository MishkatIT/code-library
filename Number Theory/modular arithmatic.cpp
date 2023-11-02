const ll mod = 1000000007;

void modNormalize(ll &x) {
    x %= mod;
    if (x < 0) {
        x += mod;
    }
}

ll modMultiply(ll x, ll y) {
    x %= mod;
    y %= mod;
    modNormalize(x);
    modNormalize(y);
    return (x * y) % mod;
}

ll modAdd(ll x, ll y) {
    x %= mod;
    y %= mod;
    modNormalize(x);
    modNormalize(y);
    return (x + y) % mod;
}

ll modSubtract(ll x, ll y) {
    x %= mod;
    y %= mod;
    modNormalize(x);
    modNormalize(y);
    x -= y;
    modNormalize(x);
    return x;
}

ll modPower(ll base, ll exponent) {
    ll result = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            result = modMultiply(result, base);
        }
        base = modMultiply(base, base);
        exponent >>= 1;
    }
    return result;
}

ll modInverse(ll x) {
    return modPower(x, mod - 2);  // Assuming mod is prime.
}

ll modDivide(ll x, ll y) {
    return modMultiply(x, modInverse(y));
}



const ll mod = 1000000007;

void modNormalize(ll &x) { x %= mod; if (x < 0) x += mod; }

ll modMultiply(ll x, ll y) { x %= mod, y %= mod; modNormalize(x), modNormalize(y); return (x * y) % mod; }
ll modAdd(ll x, ll y) { x %= mod, y %= mod; modNormalize(x), modNormalize(y); return (x + y) % mod; }
ll modSubtract(ll x, ll y) { x %= mod, y %= mod; modNormalize(x), modNormalize(y); x -= y; modNormalize(x); return x; }

ll modPower(ll base, ll exponent) { ll result = 1; while (exponent > 0) { if (exponent & 1) result = modMultiply(result, base); base = modMultiply(base, base); exponent >>= 1; } return result; }
ll modInverse(ll x) { return modPower(x, mod - 2); }  /// if mod is prime.
ll modDivide(ll x, ll y) { return modMultiply(x, modInverse(y)); }

