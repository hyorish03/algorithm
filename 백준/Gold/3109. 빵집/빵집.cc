#include <iostream>
#define FASTIO  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

using namespace std;

int h, w, cnt = 0;
int Map[10001][501];
int dy[3] = {-1, 0, 1};
int dx[3] = {1, 1, 1};

void input() {
    string in;
    cin >> h >> w;
    for(int i = 0; i < h; i++) {
        cin >> in;
        for(int j = 0; j < w; j++) {
            if(in[j] == '.') Map[i][j] = 0;
            else Map[i][j] = 1;
        }
    }
}

bool dfs(int y, int x) {
    if(x == w - 1) {
        cnt++;
        return true;
    }
    
    Map[y][x] = 1;
    
    for(int i = 0; i < 3; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && ny < h && nx >= 0 && nx < w && !Map[ny][nx]) {
            if(dfs(ny, nx)) return true;
        }
    }
    
    return false;
}

int main() {
    FASTIO;
    
    input();

    for(int i = 0; i < h; i++) {
        dfs(i, 0);
    }
    cout << cnt << '\n';
    
    return 0;
}
