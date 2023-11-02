#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<bool> vis(N + 1, false);
vector<int> adj[N];

void dfs(int node) {
    vis[node] = true;
    for (auto neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int nodes, edges, a, b, start;

    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> start;
    dfs(start);

    return 0;
}

