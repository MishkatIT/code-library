#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 2e5 + 5;
using ll = long long;

vector<int> parent(N);


vector<pair<ll, ll>> adj[N];
vector<ll> dist(N, INF);

void dijkstra(int src)
{
    dist[src] = 0;
    set<pair<int, int>> s;
    s.insert({0, src});

    while (!s.empty()) {
        int u = s.begin()->second;
        s.erase(s.begin());

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                s.erase({dist[v], v});
                dist[v] = dist[u] + w;
                s.insert({dist[v], v});
            }
        }
    }
}

void printPath(int s, int e) {
    if (s == e) {
        cout << s << ' ';
        return;
    }
    printPath(s, parent[e]);
    cout << e << ' ';
}

int main()
{
    int V, E;
    cin >> V >> E;

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int src;
    cin >> src;

    dijkstra(src);

    return 0;
}
