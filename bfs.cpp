#include <iostream>
#include <queue>
using namespace std;
#define MAX 100 
void bfs(int adj[][MAX], int visited[], int n, int start) {
     queue<int> q;
     visited[start] = 1;
     q.push(start);
     while (!q.empty()) { 
        int u = q.front();
        q.pop();
        cout << u << " "; 
        for (int v = 0; v < n; v++) { 
            if (adj[u][v] && !visited[v]) { 
            visited[v] = 1; q.push(v); 
            } 
        }
     }
}
int main() { 
    int adj[MAX][MAX] = {0};
    int visited[MAX] = {0}; 
    int n, e; 
    cout << "Enter number of nodes: "; 
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Enter edges (u v):\n"; 
    for (int i = 0; i < e; i++) { 
        int u, v; 
        cin >> u >> v; 
        adj[u][v] = 1;
        adj[v][u] = 1; // For undirected graph 
    } 
    int start; 
    cout << "Enter starting vertex: "; 
    cin >> start; 
    cout << "BFS Traversal: ";
    bfs(adj, visited, n, start);
    cout << endl;
    return 0; 
}


