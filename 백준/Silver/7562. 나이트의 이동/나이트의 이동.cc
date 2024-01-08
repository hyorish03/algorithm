#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define MAX 301

using namespace std;
int curx, cury, desx, desy;
int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
queue<pair<int, int>> q;
int vis[MAX][MAX];
int t, m;

void reset(){
    while(!q.empty()){ q.pop(); }
    memset(vis, 0, sizeof(vis));
}

void bfs(int curx, int cury){
    q.push({curx, cury});
    vis[curx][cury] = 1;  // 시작점의 방문 여부를 1로 초기화
    
    while(!q.empty()){
        curx = q.front().first;
        cury = q.front().second;
        q.pop();
        
        if(curx == desx && cury == desy){
            cout << vis[curx][cury] - 1 << '\n';  // 목적지에 도달했을 때 이동 횟수를 출력
            return;
        }
        
        for(int i = 0; i < 8; i++){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= m || ny >= m)
                continue;
            
            if(vis[nx][ny] == 0){
                vis[nx][ny] = vis[curx][cury] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> m;
        cin >> curx >> cury >> desx >> desy;
        
        reset();  // 각 테스트 케이스마다 초기화
        bfs(curx, cury);
    }
    
    return 0;
}
