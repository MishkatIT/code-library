#include<bits/stdc++.h>
using namespace std;
void printPowerSet(const string& str) {
    int n = str.length();
    int sz = (1 << n);
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << str[j];
            }
        }
        cout << endl;
    }
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    cout << "Power set of " << str << ":\n";
    printPowerSet(str);

    return 0;
}
