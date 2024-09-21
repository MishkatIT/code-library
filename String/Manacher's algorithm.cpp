#include <bits/stdc++.h>
using namespace std;

string manacher(string& str) {
    string t = "#";
    for (auto& i : str) {
        t += i;
        t += "#";
    }
    int n = t.size();
    vector<int> p(n);
    int center = 0, right = 0;
    for (int i = 0; i < n; i++) {
        int mirror = 2 * center - i;
        if (i < right) {
            p[i] = min(p[mirror], right - i);
        }
        while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
            p[i]++;
        }
        if (i + p[i] > right) {  
            right = i + p[i];
            center = i;
        }
    }
    int mx = 0, c = -1;
    for (int i = 0; i < n; i++) {
        if (p[i] > mx) {
            mx = p[i];
            c = i;
        }
    }
    int start = (c - mx) / 2;
    return str.substr(start, mx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        string str;
        cin >> str;
        cout << manacher(str) << '\n';
    }
    return 0;
}

