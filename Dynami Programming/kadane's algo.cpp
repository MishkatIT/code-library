/*
    author    : MishkatIT
    created   : Saturday 2023-11-18-19.02.21
*/

#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(_) cout << #_ << " is " << _ << '\n';

using namespace std;
using ll        = long long;
using ld        = long double;
const ll mod    = 1e9 + 7;
const ll N      = 2e5 + 10;
const ll inf    = 1e9;
const ll linf   = 1e18;

ll maxSubArraySum(vector<int>& v, int l, int r)
{
    ll sum = 0;
    ll mxSum = v[l];
    while(l <= r) {
        sum += v[l++];
        mxSum = max(mxSum, sum);
        sum = max(0LL, sum);
        // whenever the sum is less than zero,
        // then reset the sum to zero,
        // because carrying the negative part is not beneficial.
    }
    return mxSum;
}

int main()
{
    fio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto& i : v) {
            cin >> i;
        }
        cout << maxSubArraySum(v, 0, n - 1) << '\n';
    }
    return 0;
}

