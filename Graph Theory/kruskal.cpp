#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int source, destination, weight;
};

// Structure to represent a disjoint-set data structure
struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

// Kruskal's algorithm to find the minimum spanning tree
vector<Edge> kruskalMST(vector<Edge>& edges, int V) {
    vector<Edge> minimumSpanningTree;
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    DisjointSet dsu(V);

    for (const Edge& edge : edges) {
        if (dsu.find(edge.source) != dsu.find(edge.destination)) {
            minimumSpanningTree.push_back(edge);
            dsu.unionSets(edge.source, edge.destination);
        }
    }

    return minimumSpanningTree;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter the source, destination, and weight for each edge:\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    vector<Edge> minimumSpanningTree = kruskalMST(edges, V);

    cout << "Minimum Spanning Tree:\n";
    for (const Edge& edge : minimumSpanningTree) {
        cout << edge.source << " - " << edge.destination << " (Weight: " << edge.weight << ")\n";
    }

    return 0;
}


/*

4 5
0 1 10
1 3 15
2 3 4
2 0 6
0 3 5

*/
