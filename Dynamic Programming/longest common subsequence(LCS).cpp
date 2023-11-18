#include <bits/stdc++.h>
using namespace std;

int lcsubsequence(string &s1, string &s2) {
    int n = s1.size(), m = s2.size(), ans = 0;
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, cur[j] = (s1[i - 1] == s2[j - 1]) ? 1 + prev[j - 1] : 0);
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

    int length = lcsubsequence(s1, s2);

    cout << "Length of Longest Common Subsequence: " << length << endl;

    return 0;
}
