#include <bits/stdc++.h>
using namespace std;

class trieNode{
public:
    bool isEnd;
    trieNode* child[26];
    trieNode() {
        isEnd = false;
        fill(begin(child), end(child), nullptr);
    }
};

class trie{
public:
    trieNode* root;
    trie() {
        root = new trieNode;
    }

    int getIdx(char c) {
        return c - 'a';
    }

    void insert(const string& word) {
        trieNode* node = root;
        for (auto& c: word) {
            int idx = getIdx(c);
            if (!node->child[idx]) {
                node->child[idx] = new trieNode();
            } 
            node = node->child[idx];
        }
        node->isEnd = true;
    } 
    
    bool search(const string& word) {
        trieNode* node = root;
        for (auto& c : word) {
            int idx = getIdx(c);
            if (!node->child[idx]) return false;
            node = node->child[idx];
        }
        return node->isEnd;
    }

    bool isPrefix(const string& pref) {
        trieNode* node = root;
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
        trie tr;
        string word = "hello";
        tr.insert(word);
        cout << tr.search("rand");
    }
    return 0;
}



