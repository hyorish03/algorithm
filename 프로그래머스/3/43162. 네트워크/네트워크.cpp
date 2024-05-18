#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;
vector<vector<int>> v;
int answer = 0;
int vis[10001];
void bfs(int start){
    queue<int> q;
    q.push(start);
    vis[start] = true;
    
    while(!q.empty()){
        int current = q.front();
        q.pop();
        
        for(int i=0; i<v.size(); i++) {
            if(i == current) continue;
            if(!vis[i] && v[current][i] == 1) {
                vis[i] = true;
                q.push(i);
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    v = computers;
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < v.size(); i++){
        if(!vis[i]){
            bfs(i);
            answer++;
        }
    }
    
    return answer;
}