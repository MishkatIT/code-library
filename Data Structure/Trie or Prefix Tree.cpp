#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    bool isEnd;
    TrieNode* child[26];
    TrieNode() {
        isEnd = false;
        fill(begin(child), end(child), nullptr);
    }
};

class Trie{
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode;
    }

    int getIdx(char c) {
        return c - 'a';
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (auto& c: word) {
            int idx = getIdx(c);
            if (!node->child[idx]) {
                node->child[idx] = new TrieNode();
            } 
            node = node->child[idx];
        }
        node->isEnd = true;
    } 
    
    bool search(const string& word) {
        TrieNode* node = root;
        for (auto& c : word) {
            int idx = getIdx(c);
            if (!node->child[idx]) return false;
            node = node->child[idx];
        }
        return node->isEnd;
    }

    bool isPrefix(const string& pref) {
        TrieNode* node = root;
        for (auto& c: pref) {
            int idx = getIdx(c);
            if (!node->child[idx]) return false;
            node = node->child[idx];
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
        string word = "hello";
        tr.insert(word);
        cout << tr.search("rand");
    }
    return 0;
}