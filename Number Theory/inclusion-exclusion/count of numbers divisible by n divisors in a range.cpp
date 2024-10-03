#include<bits/stdc++.h>
using namespace std;

int countDivisible(int n, int x) {
    return n / x;
}

int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

int main() {
    int n = 100;
    vector<int> divisors = {2, 3, 5, 9};
    int m = divisors.size();
    int result = 0;

    // Loop through all subsets of divisors using bitmasking
    for (int mask = 1; mask < (1 << m); ++mask) {
        int lcmValue = 1;
        int bitsCount = 0;

        for (int i = 0; i < m; ++i) {
            if (mask & (1 << i)) {
                lcmValue = lcm(lcmValue, divisors[i]);
                bitsCount++;
            }
        }

        if (bitsCount % 2 == 1) { // Add for odd-sized subsets
            result += countDivisible(n, lcmValue);
        } else { // Subtract for even-sized subsets
            result -= countDivisible(n, lcmValue);
        }
    }

    cout << "Count of integers between 1 and 100 divisible by 2, 3, 5, or 9: " << result << endl;

    return 0;
}
