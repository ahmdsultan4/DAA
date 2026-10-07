#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

vector<int> run_digikstra(const vector<vector<pair<int,int>>>& adj, int start) {

    vector<int> dist(adj.size(),INT_MAX);

    dist[start] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});

    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d>dist[u])
            continue;
        for (auto [v,w] : adj[u]) {
            if (dist[u]+w < dist[v]) {
                dist[v] = dist[u]+w;
                pq.push({dist[v],v});
            }
        }
        
    }
    return dist;
}
int main() {

    int v,d,size;

    cout<<"Enter the number of vertices: ";
    cin>>size;

    vector<vector<pair<int,int>>> adj(size);

    for (int i=0;i<size;i++) {
        do {
            cout<<"Enter Neighbour Vertex Distance of Vectex "<<i<<"(Enter -1,-1 To Stop Reading): ";
            cin>>v>>d;
            if (v == -1 && d == -1)
                break;
            adj[i].push_back({v,d});
        } while (true);
    }

    vector<int> distances = run_digikstra(adj,0);

    for (int i=0;i<size;i++) {
        cout<<"Distance from Node 0 to Node "<<i<<" is : "<<distances[i]<<endl;
    }
    return 0;
}