#include <iostream>
#include <queue>
#include <cstring>
#define FASTIO  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define MAX 1001
using namespace std;

int arr[MAX][MAX];
int vis[MAX];
int n, v, st;
queue<int> q;
void dfs(int cur){
    vis[cur] = true;
    cout << cur << ' ';
    for(int i = 1; i <= n; i++){
        if(!vis[i] && arr[cur][i]){
            dfs(i);
        }
    }
    
}

void bfs(int st){

    q.push(st);
    vis[st] = true;
    
    while(!q.empty()){
        int cur = q.front();
        cout << cur << ' ';

        q.pop();
        for(int i = 1; i <= n; i++){
            if(vis[i] == 0 && arr[cur][i] == 1){
                q.push(i);
                vis[i] = true;
            }
        }
    }
}
int main() {
    FASTIO;
   
    cin >> n >> v >> st;
   
    for(int i = 0; i < v; i++){
        int a, b;
        cin >> a >> b;
        
        arr[a][b] = true;
        arr[b][a] = true;
    }
    
    dfs(st);
    memset(vis, 0, sizeof vis);
    cout << '\n';
    bfs(st);
    return 0;
}

