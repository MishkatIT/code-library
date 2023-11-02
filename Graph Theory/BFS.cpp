#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<bool> vis(N + 1, false);
vector<int> adj[N];

void bfs(int startNode) {
    queue<int> q;

    vis[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        for (auto neighbor : adj[currentNode]) {
            if (!vis[neighbor]) {
                vis[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int nodes, edges, u, v, start;

    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> start;
    bfs(start);

    return 0;
}

