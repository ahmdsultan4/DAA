#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(const vector<vector<int>>& adj, int start, int size) {
    queue<int> q;
    q.push(start);
    vector<bool> is_visited(size,false);
    while(!q.empty()) {
        int curr = q.front();
        cout<<" "<<curr;
        q.pop();
        for (int v : adj[curr]) {
            if (!is_visited[v]) {
                is_visited[v]=true;
                q.push(v);
            }
        }
    }

}
int main() {
    int size,start,v,d;
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

    bfs(adj,start,size);
    return 0;
}