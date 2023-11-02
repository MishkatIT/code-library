#include <bits/stdc++.h>
using namespace std;

int lcSubstring(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                int val = 1 + prev[j - 1];
                cur[j] = val;
                ans = max(ans, val);
            } else
                cur[j] = 0;
        }
        prev = cur;
    }
    return ans;
}

int main() {
    string s1, s2;

    cout << "Enter the first string: ";
    cin >> s1;

    cout << "Enter the second string: ";
    cin >> s2;

    int length = lcSubstring(s1, s2);

    cout << "Length of Longest Common Substring: " << length << endl;

    return 0;
}

