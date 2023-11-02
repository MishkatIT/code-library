#include <bits/stdc++.h>
using namespace std;

long long binaryExponentiation(long long x, long long n) {
    long long result = 1;

    while (n > 0) {
        if (n % 2 == 1) {
            result *= x;
        }

        x *= x;
        n /= 2;
    }

    return result;
}

int main() {
    long long x, n;
    cin >> x >> n;

    long long result = binaryExponentiation(x, n);
    cout << result << endl;

    return 0;
}
