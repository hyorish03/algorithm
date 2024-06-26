#include <iostream>
#include <queue>
#include <cstring>
#define FASTIO  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define MAX 1001
using namespace std;

int h, w;
bool vis[27];
int root[27];
int arr[31][31];
int ans = 0;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void dfs(int y, int x, int depth){
    int num = arr[y][x];
    vis[num] = true;
    ans = max(ans, depth);

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;

        int nextNum = arr[ny][nx];
        if(!vis[nextNum]){
            dfs(ny, nx, depth + 1);
        }
    }
    vis[num] = false;
}

int main() {
    FASTIO;
    
    cin >> h >> w;
    
    for(int i = 0; i < h; i++){
        string s;
        cin >> s;
        for(int j = 0; j < w; j++){
            arr[i][j] = s[j] - 'A';
        }
    }

    dfs(0, 0, 1);

    cout << ans << '\n';
    return 0;
}
