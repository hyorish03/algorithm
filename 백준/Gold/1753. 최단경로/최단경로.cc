#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define MAX 20001

struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

vector<Edge> graph[MAX];
int dist[MAX];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;
    
    while (!pq.empty()) {
        int curr = pq.top().second;
        int curr_dist = pq.top().first;
        pq.pop();
        
        if (dist[curr] < curr_dist) continue;
        
        for (const auto& edge : graph[curr]) {
            int next = edge.to;
            int next_dist = curr_dist + edge.weight;
            
            if (next_dist < dist[next]) {
                dist[next] = next_dist;
                pq.push({next_dist, next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int v, e, k;
    cin >> v >> e >> k;
    
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }
    
    fill(dist, dist + v + 1, numeric_limits<int>::max());
    
    dijkstra(k);
    
    for (int i = 1; i <= v; ++i) {
        if (dist[i] == numeric_limits<int>::max())
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
    
    return 0;
}
