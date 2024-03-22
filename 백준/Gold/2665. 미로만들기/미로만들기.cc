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
int dy[] ={0, 0, 1, -1};
int dx[] ={1, -1,0, 0};
int w, h;

void bfs(int y, int x){
    queue<pair<int,int>> q;
    q.push({y,x});
    vis[y][x] = arr[y][x];
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nCost = arr[ny][nx] + vis[y][x];
//            cout << "("<< ny << ", " << nx << ") cost: " << nCost << endl;

            if(ny >= w || ny < 0 || nx >= w || nx < 0 ) continue;
            if(vis[ny][nx] > nCost){
                vis[ny][nx] = nCost;
//                cout << "("<< ny << ", " << nx << ") cost: " << nCost << endl;
                q.push({ny, nx});
            }
            
        }
    }
}
int main() {

    cin >> w ;
    
    for(int i = 0; i < w; i++){
        string s;
        cin >> s;
        for(int j = 0; j < w; j++){
            int t = s[j]-'0';
            if(t == 1){
                arr[i][j] = 0;}
            if(t==0) arr[i][j] = 1;
        }
    }
//    cout << endl;
    for(int i = 0; i < w; i++){
        for(int j = 0; j < w; j++){
//            cout << arr[i][j];
            vis[i][j] = 9999;
        }
//        cout << endl;
    }
    bfs(0, 0);

    cout << vis[w-1][w-1];
    return 0;
}

