#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX 1000
using namespace std;
int arr[MAX][MAX];
int vis[MAX];
int dy[] ={0, 0, 1, -1};
int dx[] ={1, -1,0, 0};
int w, h;
vector<vector<int>> v(MAX);
vector<int> ord;
int n, m;
void dfs(int k){
    vis[k] = 1;
    for(int e: v[k]){
        if(!vis[e]){
            dfs(e);
        }
    }
    return;
}

int main() {
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int n;
            cin >> n;
            if(i == j) continue;
            if(n == 1){
                v[i].push_back(j);
            }
        }
    }

    int cnt = 0;
    
    for(int i=0; i < m; i++){
            int x;
            cin >> x;
            if(!vis[x]){
                cnt++;
                dfs(x);
            }
        }
    if(cnt == 1) cout << "YES";
    else cout << "NO";
    

    return 0;
}

