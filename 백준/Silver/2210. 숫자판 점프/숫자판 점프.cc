#include <iostream>
#include <set>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int arr[5][5];
set<int> str;
bool vis[5][5];

void dfs(int y, int x, int num, int cnt){
    if(cnt == 6){
        str.insert(num);
        return;
    }
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            dfs(ny, nx,num*10 + arr[ny][nx], cnt+1);
        }
    }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            dfs(i, j, arr[i][j], 1);
        
        }
    }
    
    cout << str.size();
    
    return 0;
}
