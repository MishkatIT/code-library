#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> adj(n);
        vector<int> inDegree(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (int v : adj[u]) {
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        if (topo.size() == n) {
            for (int i : topo) {
                cout << i << ' ';
            }
            cout << '\n';
        } else {
            cout << "Cycle detected, no topological sort possible." << '\n';
        }
    }

    return 0;
}


/*
    1
    6 6
    2 3
    3 1
    4 0
    4 1
    5 0
    5 2
*/