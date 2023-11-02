#include <bits/stdc++.h>
using namespace std;

vector<int> totient;

vector<int> eulerTotientRange(int n) {
    totient.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        totient[i] = i;
    }

    for (int p = 2; p <= n; ++p) {
        if (totient[p] == p) {
            for (int j = p; j <= n; j += p) {
                totient[j] -= totient[j] / p;
            }
        }
    }

    return totient;
}

int main() {
    int n;
    cout << "Enter a positive integer n: ";
    cin >> n;

    eulerTotientRange(n);

    cout << "Euler's Totient (Phi) Function for numbers from 1 to " << n << ":\n";
    for (int i = 1; i <= n; ++i) {
        cout << "Phi(" << i << ") = " << totient[i] << "\n";
    }

    return 0;
}
