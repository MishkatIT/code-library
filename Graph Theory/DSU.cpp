#include <iostream>
#include <vector>

using namespace std;

class DSU {
public:
    vector<int> parent, child;

    DSU(int n) {
        parent.resize(n);
        child.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int root(int x) {
        return (parent[x] != x) ? (parent[x] = root(parent[x])) : x;
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
    int n;
//    cin >> n;
//
    DSU dsu(n = 5);

    // Example usage:
    dsu.join(0, 1);
    dsu.join(2, 3);
    dsu.join(0, 2);

    cout << "Are 1 and 2 in the same set? " << (dsu.root(1) == dsu.root(2) ? "Yes" : "No") << '\n';

    return 0;
}
