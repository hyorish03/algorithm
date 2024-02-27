#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
#define INF 987654321
#define MAX 1001
using namespace std;
vector<int> ans;
int vis[MAX] = {0,};
struct Node {
    int node;
    int dist;
};

int start, dest, result = MAX, minDist = 0;
int n, m;
vector<vector<Node>> v(MAX);
int dfs(int node, int dest, int dist){
//    cout << "node: " << node << "dist: " << dist << endl;
    vis[node] = true;
    
    if(node == dest){
        return dist;
    }
    int minDist = INF;
    for(int i = 0; i < v[node].size(); i++){
        int nextNode = v[node][i].node;
        int nextDist = v[node][i].dist;
        if(!vis[nextNode]){
            int res = dfs(nextNode, dest, nextDist+dist);
            result = min(minDist, res);
        }
    }
    return result;
}

int main() {
    FASTIO;
    int from, to, dist;

    cin >> n >> m;
    for(int i = 0; i < n-1; i++){
        cin >> from >> to >> dist;
        v[from].push_back({to, dist});
        v[to].push_back({from, dist});
    }
    
    for(int i = 0; i < m; i++){
        cin >> start >> dest;
        memset(vis, 0, sizeof(vis));
        cout << dfs(start, dest, 0) << '\n';
    }
    
    return 0;
}
//4 2
//2 1 2
//4 3 2
//1 4 3
//3 1
//4 2

/**
 12 2
 1 2 3
 1 3 2
 2 4 5
 3 5 11
 3 6 9
 4 7 1
 4 8 7
 5 9 15
 5 10 4
 6 11 6
 6 12 10
 1 4
 3 6
 */
