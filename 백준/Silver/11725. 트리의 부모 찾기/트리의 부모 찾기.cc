#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

//typedef long long ll;
#define MAX 100001

using namespace std;

vector<vector<int>> v(MAX);
vector<int> par(MAX);

bool vis[MAX];

int des = 3;

void dfs(int cur){
    vis[cur] = true;

        for(int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i];
            if(!vis[next]){
                dfs(next);
                par[next] = cur;
            }
        }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

//    v.resize(n+1);
//    par.resize(n+1);
    
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    dfs(1);
    
    for(int i = 2; i <= n; i++){
        cout << par[i] << '\n';
    }
    return 0;
}
