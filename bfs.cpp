#include <iostream>
#include <queue>
using namespace std;
const int MAX = 100;
void bfs(int graph[MAX][MAX], int n, int start) {
    if (start < 0 || start >= n) {
        cout << "Error: Invalid starting vertex!" << endl;
        return;
    }
    bool visited[MAX] = {0}; // Track visited vertices
    queue<int> q;
    visited[start] = true;
    q.push(start);
    cout << "BFS Traversal starting from vertex " << start << ": ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v = 0; v < n; v++) {
            if (graph[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}
void displayGraph(int graph[MAX][MAX], int n) {
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << graph[i][j] << " ";
        cout << endl;
     }
}
int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    int graph[MAX][MAX];
    cout << "Enter adjacency matrix (0 or 1):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    displayGraph(graph, n);
    int start;
    cout << "Enter starting vertex for BFS: ";
    cin >> start;
    bfs(graph, n, start);
    return 0;
}
