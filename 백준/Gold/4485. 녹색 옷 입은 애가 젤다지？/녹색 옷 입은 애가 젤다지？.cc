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
int idx = 1;

struct Q {
    int cost;
    int y;
    int x;
    
    bool operator<(const Q& other) const {
        return cost > other.cost; // 비용이 작은 것이 먼저 오도록
    }
};
void bfs(int y, int x){
    
    priority_queue<Q, vector<Q>> pq;
    vis[y][x] = arr[y][x];
    pq.push({arr[y][x], y, x});
    
    while(!pq.empty()){
        int y = pq.top().y;
        int x = pq.top().x;
        int cost = pq.top().cost;
        pq.pop();
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < n && nx < n && ny >= 0 && nx >= 0){
                int temp = cost + arr[ny][nx];
                if(vis[ny][nx] > temp){
                    vis[ny][nx] = temp;
                    pq.push({temp,ny, nx});
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
