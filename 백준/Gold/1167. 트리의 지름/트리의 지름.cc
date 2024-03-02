#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>
#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
#define MAX 100001
using namespace std;
vector<int> ans;
int vis[MAX] = {0,};
int maxDist = -1, maxNode = 1;

struct Node {
    int node;
    int dist;
};

vector<vector<Node>> v(MAX);

void dfs(int start, int dist){
    if(vis[start]){
        return;
    }
    
    if(maxDist <= dist){
        maxDist = dist;
        maxNode = start;
    }
    
    vis[start] = true;
    
    for(int i = 0; i < v[start].size(); i++){
        int nextNode = v[start][i].node;
        int nextDist = v[start][i].dist;
        
        dfs(nextNode, nextDist + dist);
    }
    
}

int main() {
    FASTIO;
    
    int n; // 노드의 개수
    cin >> n;
    
    int from, to, dist;

    for(int i = 1; i < n+1; i++){
        cin >> from;
        while(1){
            cin >> to;
            if(to == -1)
                break;
            cin >> dist;
            v[from].push_back({to, dist});
            v[to].push_back({from, dist});
        }

    }
    
//    for(int i = 1; i <= n; i++){
        dfs(1,0);
        memset(vis, 0, sizeof(vis));
        dfs(maxNode, 0);
        cout << maxDist;
//    }
    return 0;
}
