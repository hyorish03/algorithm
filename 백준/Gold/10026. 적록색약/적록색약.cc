#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAX 1001

using namespace std;

char arr[MAX][MAX];
char blind[MAX][MAX];

bool visited[MAX][MAX] = {0, };
queue<pair<int, int>> q;
int dx[] ={0, 0, 1, -1};
int dy[] ={1, -1, 0, 0};
int n;

void bfs(int y, int x, int temp){
    visited[y][x] = true;
    q.push({y, x});
    
    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || ny >= n || nx >= n)
                continue;
            if(temp == 0){
                if(visited[ny][nx] == false && arr[y][x] == arr[ny][nx]){
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            } else if(temp == 1){
                if(visited[ny][nx] == false && blind[y][x] == blind[ny][nx]){
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
        
    }
}

int main() {
    FASTIO;
    
    cin >> n;
    
    for(int i = 0; i <n; i++){
        for(int j = 0; j <n; j++){
            char c;
            cin >> c;
            arr[i][j] = c;
            if(c == 'G'){
                c = 'R';
                blind[i][j] = c;
            } else {
                blind[i][j] = c;
            }
        }
    }

    
    
    int cnt1 = 0, cnt2 = 0;;
    
    // 비적록색약
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] == false){
                bfs(i, j, 0);
                cnt1++;
            }
        }
    }

    memset(visited, 0, sizeof(visited));

    // 적록색약
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] == false){
                bfs(i, j, 1);
                cnt2++;
            }
        }
    }

    cout << cnt1 << ' ' << cnt2 << endl;

    return 0;
}
