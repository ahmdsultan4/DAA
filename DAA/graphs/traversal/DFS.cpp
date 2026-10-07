#include<iostream>
#include<vector>
using namespace std;

void dfs_helper(const vector<vector<int>>& adj, int curr, vector<bool>& is_visited) {
    is_visited[curr] = true;
    cout << " " << curr;

    for (int v : adj[curr]) {
        if (!is_visited[v]) {
            dfs_helper(adj, v, is_visited);
        }
    }
}

void dfs(const vector<vector<int>>& adj, int start, int size) {
    vector<bool> is_visited(size, false);
    dfs_helper(adj, start, is_visited);
}

int main() {
    int size, start, v, d;

    cout << "Enter the number of nodes: ";
    cin >> size;

    vector<vector<int>> adj(size);

    for (int i = 0; i < size; i++) {
        do {
            cout << "Enter Neighbour Vertex of Vertex " << i << " (Enter -1 to stop): ";
            cin >> v;
            if (v == -1)
                break;
            adj[i].push_back(v);
        } while (true);
    }

    cout << "Enter the starting node: ";
    cin >> start;
    dfs(adj, start, size);
    return 0;
}
