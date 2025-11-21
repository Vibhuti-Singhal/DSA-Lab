#include <iostream>
using namespace std;
void createGraph(int vertices, int graph[][10]) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }
}
void addEdge(int graph[][10], int u, int v, bool directed = false) {
    graph[u][v] = 1;
    if (!directed)
        graph[v][u] = 1;
}
void displayGraph(int graph[][10], int vertices) {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int vertices, edges;
    int graph[10][10];  // Maximum 10 vertices
    cout << "Enter number of vertices (max 10): ";
    cin >> vertices;
    createGraph(vertices, graph);
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Enter edges (u v) as 0-based indices:\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(graph, u, v, false);  // false = undirected graph
    }
     displayGraph(graph, vertices);
     return 0;
}

