#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void run_prims(const vector<vector<pair<int, int>>>& adj, int size) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<bool> in_mst(size, false);
    
    pq.push({0, {0, -1}});
    int mst_weight = 0;

    cout << "Edges in the Minimum Spanning Tree:\n";
    while (!pq.empty()) {
        auto [w, edge] = pq.top();
        pq.pop();
        auto [u, parent] = edge;

        if (in_mst[u]) continue;
        in_mst[u] = true;

        if (parent != -1) {
            cout << parent << " - " << u << " : " << w << endl;
            mst_weight += w;
        }

        for (auto [v, weight] : adj[u]) {
            if (!in_mst[v]) {
                pq.push({weight, {v, u}});
            }
        }
    }
    
    cout << "Total Weight of MST: " << mst_weight << endl;
}

int main() {
    int v, d, size;
    cout << "Enter the number of vertices: ";
    cin >> size;
    
    vector<vector<pair<int, int>>> adj(size);
    for (int i = 0; i < size; i++) {
        do {
            cout << "Enter Neighbour Vertex Distance of Vertex " << i << " (Enter -1,-1 To Stop Reading): ";
            cin >> v >> d;
            if (v == -1 && d == -1)
                break;
            adj[i].push_back({v, d});
        } while (true);
    }
    
    run_prims(adj, size);
    return 0;
}