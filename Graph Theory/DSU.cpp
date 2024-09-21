#include<bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, child;

    DSU(int n) {
        parent.resize(n);
        child.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int root(int x) {
        return ((parent[x] == x) ? x : parent[x] = root(parent[x])); 
    }

    void join(int u, int v) {
        int rootU = root(u);
        int rootV = root(v);

        if (rootU != rootV) {
            if (child[rootU] < child[rootV]) {
                swap(rootU, rootV);
            }
            parent[rootV] = rootU;
            child[rootU] += child[rootV];
        }
    }
};

int main() {

    mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

    int n = rnd() % 20 + 1;

    DSU dsu(n);

    for (int i = 0; i < n / 2; i++) {
        dsu.join(rnd() % n, rnd() % n);
    }
    int query = rnd() % n;
    for (int i = 0; i < query; i++) {
        int x = rnd() % n;
        cout << "Root of " << x << " is " << dsu.root(x) << '\n'; 
    }
    return 0;
}