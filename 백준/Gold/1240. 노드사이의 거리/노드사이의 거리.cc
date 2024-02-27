#include <iostream>
#include <vector>
#include <cstring>
#define MAX 10001
#define INF 987654321
#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<vector<pair<int, int>>> v(MAX);
int vis[MAX];

int dfs(int node, int dest, int dist) {
    vis[node] = true;
    
    if (node == dest)
        return dist;
    
    int minDist = INF;
    for (auto next : v[node]) {
        int nextNode = next.first;
        int nextDist = next.second;
        if (!vis[nextNode]) {
            int res = dfs(nextNode, dest, dist + nextDist);
            minDist = min(minDist, res);
        }
    }
    return minDist;
}

int main() {
    FASTIO;
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n - 1; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;
        v[from].push_back({to, dist});
        v[to].push_back({from, dist});
    }
    
    for (int i = 0; i < m; i++) {
        memset(vis, 0, sizeof(vis));
        int start, dest;
        cin >> start >> dest;
        cout << dfs(start, dest, 0) << '\n';
    }
    
    return 0;
}
