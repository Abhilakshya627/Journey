//Assume a directed/undirected graph with n vertices and m edges. Design and implement an algorithm using a program to find if a path exists between two given vertices. The algorithm should be efficient and should work for both directed and undirected graphs.
#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int target, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    if (node == target) return true; 

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, target, graph, visited)) return true; 
        }
    }
    return false; 
}

int main() {
    int n, m; 
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    vector<vector<int>> graph(n); 
    cout << "Enter edges (u v) for directed graph:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); 
    }
    int start, end;
    cout << "Enter start and end vertices to check path: ";
    cin >> start >> end;
    vector<bool> visited(n, false); 
    if (dfs(start, end, graph, visited)) {
        cout << "Path exists between " << start << " and " << end << endl;
    } else {
        cout << "No path exists between " << start << " and " << end << endl;
    }

    return 0;
}