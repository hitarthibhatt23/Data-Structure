
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS - Breadth First Search
void BFS(int start, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << endl;
}

// DFS - Depth First Search
void DFSUtil(int node, vector<vector<int>>& adj,
             vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFSUtil(neighbor, adj, visited);
        }
    }
}

void DFS(int start, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);

    cout << "DFS Traversal: ";
    DFSUtil(start, adj, visited);
    cout << endl;
}

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v), using vertices 0 to "
         << V - 1 << ":" << endl;

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    BFS(start, adj, V);
    DFS(start, adj, V);

    return 0;
}
