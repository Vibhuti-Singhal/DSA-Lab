#include <iostream>
using namespace std;
void addEdge(int adj[][10], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}
void printMatrix(int adj[][10], int n) {
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int n, edges;
    int adj[10][10]={0};
    cout << "Enter number of vertices:";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }
    printMatrix(adj, n);
    return 0;
}



