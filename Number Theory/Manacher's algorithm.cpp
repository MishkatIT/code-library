#include <bits/stdc++.h>
using namespace std;

string preprocessString(string s) {
    int n = s.size();
    if (n == 0) return "^$";
    string result = "^";
    for (int i = 0; i < n; i++) {
        result += "#" + s[i];
    }
    result += "#$";
    return result;
}

string longestPalindromicSubstring(string s) {
    string T = preprocessString(s);
    int n = T.size();
    vector<int> P(n, 0);
    int C = 0, R = 0; // Center and right boundary of the current palindrome
    int maxLen = 0;
    int centerIndex = 0;

    for (int i = 1; i < n - 1; i++) {
        int mirr = 2 * C - i;
        if (i < R) {
            P[i] = min(R - i, P[mirr]);
        }
        // Attempt to expand palindrome centered at i
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
            P[i]++;
        }
        // If palindrome centered at i expands past R,
        // adjust center and right boundary
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
        // Find the maximum element in P
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    string longestPalindrome = longestPalindromicSubstring(s);
    cout << "Longest Palindromic Substring: " << longestPalindrome << endl;
    return 0;
}
