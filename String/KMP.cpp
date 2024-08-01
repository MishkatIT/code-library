#include <bits/stdc++.h>
using namespace std;

void computeLPS(int m, string& ptr, vector<int>& lps) {
    int len = 0, i = 1;
    while (i < m) {
        if (ptr[i] == ptr[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len-1];
            } else {
                i++;
            }
        }
    }
}

vector<int> KMP(string& str, string& ptr) {
    int n = str.length(), m = ptr.length();
    vector<int> lps(m); 
    computeLPS(m, ptr, lps);
    vector<int> pos;
    int i = 0, j = 0;
    while (i < n) {
        if (ptr[j] == str[i]) {
            i++, j++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        if (j == m) {
            pos.push_back(i - j);
            j = lps[j - 1];
        }
    }
    return pos;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        string str, ptr;
        cin >> str >> ptr;
        vector<int> ans = KMP(str, ptr);
        int sz = ans.size();
        cout << sz << '\n';
        for (int i = 0; i < sz; i++) {
            cout << ans[i] + 1 << " \n"[i == sz - 1];
        }
    }
    return 0;
}
