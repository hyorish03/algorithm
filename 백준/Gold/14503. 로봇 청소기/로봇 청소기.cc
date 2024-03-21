#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 201

int arr[MAX][MAX];
bool vis[MAX][MAX] = {false};
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0}; // 북 동 남 서

int changeDir(int dir){
    if(dir == 0) return 3;
    else if(dir == 1) return 0;
    else if(dir == 2) return 1;
    else return 2;
}

int bfs(int h, int w, int stY, int stX, int way) {
    queue<pair<pair<int, int>, int>> q;
    q.push({{stY, stX}, way});
    vis[stY][stX] = true;
    int cnt = 1;

    while(!q.empty()){
        int curY = q.front().first.first;
        int curX = q.front().first.second;
        int way =  q.front().second;
        
        q.pop();
        
        bool flag = false;
        
        for(int i = 0; i < 4; i++){
            int nWay = changeDir(way);
            int ny = curY + dy[nWay];
            int nx = curX + dx[nWay];
            
            if(ny >= 0 && ny < h && nx >= 0 && nx < w){
                if (!vis[ny][nx] && arr[ny][nx] == 0) {
                    vis[ny][nx] = true;
                    q.push({{ny, nx}, nWay});
                    cnt++;
                    flag = true;
                    break;
                }
            }

            way = nWay;
        }
        
        if(!flag){
            int bx = curX - dx[way];
            int by = curY - dy[way];
                
            if(arr[by][bx] != 1){
                q.push({{by, bx}, way});
            }
        }
    }
        
    return cnt;
}

int main() {
    int h, w, stY, stX, way;
    cin >> h >> w >> stY >> stX >> way;
        
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> arr[i][j];
        }
    }

    cout << bfs(h, w, stY, stX, way);
    return 0;
}
