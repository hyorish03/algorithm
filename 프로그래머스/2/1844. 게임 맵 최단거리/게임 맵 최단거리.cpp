#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int answer = 0;

int dy[4] = { -1, 0, 1, 0 }; 
int dx[4] = { 0, 1, 0, -1 };
int solution(vector<vector<int> > maps) {
 
    int h = maps.size();
    int w = maps[0].size();

    vector<vector<bool>> vis(h, vector<bool>(w)); 
    vector<vector<int>> dist(h, vector<int>(w));
    queue<pair<int,int>> q;
    q.push({0,0});
    vis[0][0] = 1;
    dist[0][0] = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || nx >= w || ny >= h) { continue; }
            if (maps[ny][nx] == 0) { continue; }
            if (vis[ny][nx] ) { continue; }
          
            q.push({nx, ny});
            vis[ny][nx] = true;
            dist[ny][nx] = dist[y][x] + 1; // 이동 횟수를 저장
    
        }
    }
    
 
    
    if (dist[h-1][w-1] == 0) {
        answer = -1;
    } else {
        answer = dist[h-1][w-1];
    }

    return answer;
}
