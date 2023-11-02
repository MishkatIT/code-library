#include <bits/stdc++.h>
using namespace std;

void primeFactorization(int n) {
    for (int p = 2; p * p <= n; p++) {
        while (n % p == 0) {
            cout << p << " ";
            n /= p;
        }
    }
    if (n > 1) {
        cout << n;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Prime factorization of array elements:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        primeFactorization(arr[i]);
        cout << endl;
    }

    return 0;
}
