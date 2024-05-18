#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define MAX 201
vector<vector<int>> v(MAX);
bool vis[101] = {false,};
int s = 1;
int len = 0;
void bfs(int a, int b){
    queue<int> q;
    vis[a] = true;
    vis[b] = true;
    q.push(a);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for(int i = 0; i < v[x].size(); i++){
            if(vis[v[x][i]]) continue;
            s++;
            q.push(v[x][i]);
            vis[v[x][i]] = true;
        }
        
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    int point = 1;
    len = n-1;
    for(int i = 0; i < wires.size(); i++){
        int x = wires[i][0];
        int y = wires[i][1];
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for(int i = 0; i < n-1; i++){
        memset(vis, false, sizeof vis);

        int a = wires[i][0];
        int b = wires[i][1];
        s = 1;
        cout << "A: " << a << " B: " << b ;
        bfs(a, b);
        answer = min(answer, abs(n-s-s));
        cout << "ANS: " << answer << " S: " << abs(n-s-s) << '\n';
    }
    
 
    return answer;
}