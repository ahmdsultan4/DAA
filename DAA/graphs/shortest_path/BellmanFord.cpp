#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int u, v, weight;
};

vector<int> run_bellman_ford(int size, const vector<Edge>& edges, int start) {
    vector<int> dist(size, INT_MAX);
    dist[start] = 0;
    for (int i = 1; i <= size - 1; i++) {
        for (const auto& edge : edges) {
            if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.weight < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }
    return dist;
}

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
    vector<int> distances = run_bellman_ford(size, edges, 0);
    for (int i = 0; i < size; i++) {
        cout << "Distance from Node 0 to Node " << i << " is : " << distances[i] << endl;
    }
    return 0;
}