#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int source, destination, weight;
};

void bellmanFord(vector<Edge>& edges, int V, int source) {
    vector<int> distance(V, INT_MAX);
    distance[source] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (const Edge& edge : edges) {
            if (distance[edge.source] != INT_MAX && distance[edge.source] + edge.weight < distance[edge.destination]) {
                distance[edge.destination] = distance[edge.source] + edge.weight;
            }
        }
    }

    // Check for negative weight cycles
    for (const Edge& edge : edges) {
        if (distance[edge.source] != INT_MAX && distance[edge.source] + edge.weight < distance[edge.destination]) {
            cout << "Graph contains a negative weight cycle!" << endl;
            return;
        }
    }

    // Print the shortest distances from the source
    cout << "Shortest distances from source vertex " << source << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter the source, destination, and weight of each edge:\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    bellmanFord(edges, V, source);

    return 0;
}


/*

5 8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3
0

*/
