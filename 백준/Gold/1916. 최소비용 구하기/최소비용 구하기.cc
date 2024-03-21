#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
#define INT_MAX 987654321
typedef pair<int, int> edge;
static int V, E, K;
static vector<int> mdist;
static vector<bool> vis;
static vector<vector<edge>> mlist;
static priority_queue<edge, vector<edge>, greater<edge>> q;
int main() {
    cin >> V >> E ; // V: 노드 수, E: 간선 수, K: 시작 수
    
    mdist.resize(V+1);
    vis.resize(V+1);
    mlist.resize(V+1);
    fill(mdist.begin(), mdist.end(), INT_MAX);
    fill(vis.begin(), vis.end(), false);
    
    
    for(int i = 0; i < E; i++){
        int st, en, cost;
        cin >> st >> en >> cost;
        
        mlist[st].push_back({en,cost});
    }
    
    int fr, to;
    cin >> fr >> to;
    
    q.push({0, fr});
    mdist[fr] = 0;
    
    while(!q.empty()){
        edge cur = q.top();
        q.pop();
        
        int cv = cur.second;
        if(vis[cv])continue;
        vis[cv] = true;
        
        for(int i = 0; i < mlist[cv].size();i++){
            edge tmp = mlist[cv][i];
            int next = tmp.first;
            int cost = tmp.second;
            
            if(mdist[next] > mdist[cv]+cost){
                mdist[next] = mdist[cv]+cost;
                q.push({mdist[next], next});
            }
        }
    }
    
    cout << mdist[to];
    return 0;
}
