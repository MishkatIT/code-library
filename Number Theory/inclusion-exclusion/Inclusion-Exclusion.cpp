/*
    author    : MishkatIT
    created   : Friday 2023-11-24-01.02.30
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

string vowel = "aeiou";
bool isVowel(char c)
{
    return (vowel.find(c) != string::npos);
}


vector<string> powerSet(string str)
{
    int n = (1 << str.size());
    vector<string> all;
    for (int i = 0; i < n; i++) {
        string temp;
        for (int j = 0; j < 5; j++) {
            if (i & (1 << j)) {
                temp += str[j];
            }
        }
        if (temp.size() > 0) {
            all.push_back(temp);
        }
    }
    return all;
}

int main()
{
    fio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<string, int> mp;
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            set<char> s;
            for (auto& c : str) {
                if (isVowel(c)) {
                    s.insert(c);
                }
            }
            string temp;
            for (auto& x : s) {
                temp += x;
            }
            for (auto& x : powerSet(temp)) {
                mp[x]++;
            }
        }
        ll ans = 0;
        for (auto& i : mp) {
            ll cur = i.second;
            if (cur < 3) continue;
            ll ways = cur * (cur - 1) * (cur - 2) / 6;
            if (i.first.size() & 1) {
                ans += ways;
            } else {
                ans -= ways;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}


/*

    https://www.youtube.com/watch?v=rrH3nZ9KjCY
    https://www.hackerearth.com/problem/algorithm/the-three-musketeers-6efd5f2d/

*/