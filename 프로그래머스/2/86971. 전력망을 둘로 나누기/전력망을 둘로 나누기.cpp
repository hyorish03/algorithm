#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;
vector<vector<int>> v(202);
int s = 1;
int vis[202];
void bfs(int x, int y){
    queue<int> q;
    q.push(x);
    vis[x] = true;
    vis[y] = true;
    
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(int i = 0; i < v[f].size(); i++){
            int next = v[f][i];
            if(!vis[next]){
                q.push(next);
                vis[next] = true;
                s++;
            }
        }
    }
}
int solution(int n, vector<vector<int>> wires) {
    
    for(int i = 0; i < wires.size(); i++){
        int a = wires[i][0];
        int b = wires[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    int answer = 100;
    for(int i = 0; i < wires.size(); i++){
        int x = wires[i][0];
        int y = wires[i][1];
        s = 1;
        memset(vis, false, sizeof vis);
        bfs(x, y);
        answer = min(answer, abs(n-s*2));
    }
    return answer;
}