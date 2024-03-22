#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX 126
using namespace std;
int arr[MAX][MAX];
int vis[MAX][MAX];
int dx[] ={0, 0, 1, -1};
int dy[] ={1, -1, 0, 0};
int n;

bool valid(int ny, int nx){
    if(ny < n && nx < n && ny >= 0 && nx >= 0) return true;
    else return false;
    
}
int idx = 1;
void bfs(int y, int x){
    queue<pair<int,int>> q;
    q.push({y, x});
    vis[y][x] = arr[y][x];
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < n && nx < n && ny >= 0 && nx >= 0){
                int temp = vis[y][x] + arr[ny][nx];
                if(vis[ny][nx] > temp){
                    vis[ny][nx] = temp;
                    q.push({ny, nx});
                }
            }
        }
        
    }
}
int main() {

    while(1){
        cin >> n;
        if(n == 0) break;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                vis[i][j]=9999;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }
        
        bfs(0,0);
        
        cout << "Problem " << idx << ": " << vis[n-1][n-1] << '\n';
        idx++;
    }
    return 0;
}
/*
3
5 5 4
3 9 1
3 2 7
0
*/
