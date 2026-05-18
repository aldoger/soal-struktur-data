#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>  
using namespace std;

int vertex;
vector<vector<int>> adjList;

vector<int> bfs_path(vector<vector<int>>& adj, int dest) {
    int src = 0;
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<int> parent(V, -1); 
    queue<int> q;

    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == dest) break; 

        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                parent[x] = curr;  
                q.push(x);
            }
        }
    }

    vector<int> path;
    if (!visited[dest]) {
        return path;  
    }

    for (int v = dest; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n, destination_vertex;
    cin >> n;
    cin >> destination_vertex;
    destination_vertex--;  
    vertex = n;

    adjList.assign(n, vector<int>());
    vector<vector<int>> path(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            if (num != 0 && num != 1) {
                throw runtime_error("must be 0 or 1");
            }
            path[i][j] = num;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (path[i][j] == 1) {
                adjList[i].push_back(j);
            }
        }
    }

    vector<int> result = bfs_path(adjList, destination_vertex);
    if (result.empty()) {
        cout << "No path found!" << endl;
    } else {
        for (int i = 0; i < result.size(); i++) {
            if (i > 0) cout << " -> ";
            cout << result[i] + 1; 
        }
        cout << endl;
    }

    return 0;
}