#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int n, vector<vector<int>>& adj) {  // 0 based.
    vector<int> color(n, -1);
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int& v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = !color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v; 
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isBipartite(n, adj)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}
