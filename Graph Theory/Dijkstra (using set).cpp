
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 1000;
vector<vector<pair<int, int>>> graph(N);
vector<int> dist(N, INF);
vector<bool> vis(N, false);

void dijkstra(int source)
{
    dist[source] = 0;
    set<pair<int, int>> s;
    s.insert({0, source});

    while (!s.empty()) {
        int u = s.begin()->second;
        s.erase(s.begin());

        if (vis[u]) {
            continue;
        }

        vis[u] = true;

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                s.erase({dist[v], v});
                dist[v] = dist[u] + weight;
                s.insert({dist[v], v});
            }
        }
    }

    // Print the shortest distances from the source vertex to all nodes
    for (int i = 0; i < N; ++i) {
        if (dist[i] != INF) {
            cout << "Shortest distance from " << source << " to " << i << ": " << dist[i] << '\n';
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);

    }

    int source;
    cin >> source;

    dijkstra(source);

    return 0;
}
