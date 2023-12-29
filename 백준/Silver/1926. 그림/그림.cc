#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>  // sort 함수 사용을 위해 추가

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAX 1001

using namespace std;
int arr[MAX][MAX];
bool visited[MAX][MAX] = {0,};
queue<pair<int, int>> q;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int n, m;
int s = 1;
void bfs(int y, int x){
    visited[y][x] = true;
    q.push({y, x});
    
    while(!q.empty()){
        x = q.front().second;
        y = q.front().first;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || ny < 0 || ny >= n || nx >= m)
                continue;
            if(visited[ny][nx] == false && arr[ny][nx] == true){
                visited[ny][nx] = true;
                s++;
                q.push({ny, nx});

            }
        }
    }
}

int main() {
    FASTIO;
    vector<int> v;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] == 0 && arr[i][j] == 1){
                bfs(i, j);
                v.push_back(s);
                s = 1;
                cnt ++;
                
            }
        }
        
    }
    

    sort(v.begin(), v.end(), greater<int>());
    cout << cnt << endl;
    
    if(cnt == 0){
        cout << 0 << endl;
    } else {
        cout << v[0] << endl;
    }
    return 0;
}
