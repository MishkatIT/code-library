#include<bits/stdc++.h>

using namespace std;

// Function to perform depth-first search
void DFS(vector<vector<int>>& adj, int v, vector<bool>& visited, stack<int>& s) {
    visited[v] = true;
    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            DFS(adj, neighbor, visited, s);
        }
    }
    s.push(v);
}

// Function to fill the stack with vertices in order of their finish times
void fillOrder(vector<vector<int>>& adj, int V, stack<int>& s) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(adj, i, visited, s);
        }
    }
}

// Function to perform depth-first search on the transposed graph
void DFSReverse(vector<vector<int>>& adjTranspose, int v, vector<bool>& visited, vector<int>& component) {
    visited[v] = true;
    component.push_back(v);
    for (int neighbor : adjTranspose[v]) {
        if (!visited[neighbor]) {
            DFSReverse(adjTranspose, neighbor, visited, component);
        }
    }
}

// Function to find strongly connected components
vector<vector<int>> findSCCs(vector<vector<int>>& adj, vector<vector<int>>& adjTranspose, int V) {
    stack<int> s;
    fillOrder(adj, V, s);

    vector<vector<int>> SCCs;
    vector<bool> visited(V, false);

    while (!s.empty()) {
        int v = s.top();
        s.pop();

        if (!visited[v]) {
            vector<int> component;
            DFSReverse(adjTranspose, v, visited, component);
            SCCs.push_back(component);
        }
    }

    return SCCs;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    vector<vector<int>> adj(V);
    vector<vector<int>> adjTranspose(V);

    cout << "Enter the edges in the format (source vertex, destination vertex):\n";
    for (int i = 0; i < E; i++) {
        int src, dest;
        cin >> src >> dest;
//        --src, --dest;
        adj[src].push_back(dest);
        adjTranspose[dest].push_back(src);
    }

    vector<vector<int>> SCCs = findSCCs(adj, adjTranspose, V);

    cout << "Strongly Connected Components:\n";
    for (const vector<int>& component : SCCs) {
        for (int vertex : component) {
            cout << vertex << " ";
        }
        cout << "\n";
    }

    return 0;
}




/*

  5 5
  1 3
  1 4
  2 1
  3 2
  4 5

*/


/*

8 9
0 1
1 2
2 3
2 4
3 0
4 5
5 6
6 4
6 7


*/


/*

    https://www.programiz.com/dsa/strongly-connected-components
    
*/
