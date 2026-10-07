#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } else if (rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            } else {
                parent[root_j] = root_i;
                rank[root_i]++;
            }
            return true;
        }
        return false;
    }
};

int main() {
    int size, u, v, w;
    cout << "Enter the number of vertices: ";
    cin >> size;
    
    vector<Edge> edges;
    do {
        cout << "Enter Edge (u v w) (Enter -1 -1 -1 To Stop Reading): ";
        cin >> u >> v >> w;
        if (u == -1 && v == -1 && w == -1)
            break;
        edges.push_back({u, v, w});
    } while (true);

    sort(edges.begin(), edges.end());
    DisjointSet ds(size);
    int mst_weight = 0;

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (const auto& edge : edges) {
        if (ds.unite(edge.u, edge.v)) {
            cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
            mst_weight += edge.weight;
        }
    }
    
    cout << "Total Weight of MST: " << mst_weight << endl;
    return 0;
}