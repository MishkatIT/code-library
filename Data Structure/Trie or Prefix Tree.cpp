#include <bits/stdc++.h>
using namespace std;


struct Node {
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (char i : word) {
            if (!node->containsKey(i)) {
                node->put(i, new Node());
            }
            node = node->get(i); // move to the reference trie
        }
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for (char i : word) {
            if (!node->containsKey(i)) {
                return false;
            }
            node = node->get(i);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (char i : prefix) {
            if (!node->containsKey(i)) {
                return false;
            }
            node = node->get(i);
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        Trie tr;
        int x;
        cin >> x;
        for (int i = 0; i < x; i++) {
            string original;
            cin >> original;
            tr.insert(original);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            cout << "contains " << str  << ' ' << tr.search(str) << '\n';
            cout << "isPrefix " << str << ' ' <<tr.startsWith(str) << '\n';
        }
    }
    return 0;
}
