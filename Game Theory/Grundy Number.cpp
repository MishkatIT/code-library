/*
    Author    : MishkatIT
    Created   : Tuesday 19-11-2024 22:24:56
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ld = long double;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int inf = 1e9;
const ll linf = 1e18;

vector<int> pick{2, 3, 5};
int k = 3;
vector<int> dp(101, -1);
int grundy(int n) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    set<int> s;
    for (int i = 0; i < k; i++) {
        if (n >= pick[i]) {
            s.insert(grundy(n - pick[i]));
        }
    }
    int mex = 0;
    for (auto& i : s) {
        if (mex == i) mex++;
        else break;
    }
    return dp[n] = mex;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    grundy(100);
    debug(dp);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        if (dp[n] > 0) {
            cout << "First" << '\n';
        } else {
            cout << "Second" << '\n';
        }
    }
    return 0;
}

// https://www.hackerrank.com/contests/5-days-of-game-theory/challenges/a-game-of-stones/problem