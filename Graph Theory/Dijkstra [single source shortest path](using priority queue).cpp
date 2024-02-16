#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 1000;
vector<vector<pair<int, int>>> graph(N);
vector<int> dist(N, INF);
vector<bool> vis(N, false);

void dijkstra(int source) {
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (vis[u]) {
            continue;
        }
        vis[u] = true;

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
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

int main() {
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

/*

9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
0

*/
