#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string pattern) {
    int patternLength = pattern.length();
    vector<int> lps(patternLength, 0);

    int len = 0; // Length of the previous longest prefix suffix

    for (int i = 1; i < patternLength; ) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

void kmpSearch(string text, string pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();
    vector<int> lps = computeLPS(pattern);

    int i = 0; // Index for text[]
    int j = 0; // Index for pattern[]

    while (i < textLength) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == patternLength) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < textLength && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern to search for: ";
    cin >> pattern;

    kmpSearch(text, pattern);

    return 0;
}

