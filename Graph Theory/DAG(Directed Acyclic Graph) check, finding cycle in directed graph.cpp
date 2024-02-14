#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5 + 10;

vector<int> adj[N];
vector<bool> vis(N), pathVis(N);
bool cycle = false;

void dfs(int i) {
    vis[i] = true;
    pathVis[i] = true;
    for(auto& x : adj[i]) {
        if (!vis[x]) {
            dfs(x);
        } else {
            if (pathVis[x]) {
                cycle = true;
                return;
            }
        }
    }
    pathVis[i] = false;
}

int main() {
    fio;
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        // Clear data structures for each test case
        cycle = false;
        for (int i = 0; i < N; i++) {
            adj[i].clear();
            vis[i] = false;
            pathVis[i] = false;
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        for (int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i);
            }
        }

        cout << (cycle ? "YES" : "NO") << '\n';
    }

    return 0;
}
