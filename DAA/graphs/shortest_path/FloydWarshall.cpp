#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

void run_floyd_warshall(vector<vector<int>>& dist, int size) {
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int size;
    cout << "Enter the number of vertices: ";
    cin >> size;
    vector<vector<int>> dist(size, vector<int>(size));
    cout << "Enter the adjacency matrix (type 'INF' for infinity):\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            string s;
            cin >> s;
            if (s == "INF" || s == "inf") {
                dist[i][j] = INT_MAX;
            } else {
                dist[i][j] = stoi(s);
            }
        }
    }
    run_floyd_warshall(dist, size);
    cout << "Shortest path matrix:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}