#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#define MAX 101

using namespace std;
int tc, total, n, m;
bool vis[10000001] = {0,};
vector<int> ans;
vector<int> arr;
int maps[MAX][MAX];

void dfs(int cnt, int num){
    if(cnt == 2){
        ans.push_back(num);

        return;
    }
    
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            vis[i] = 1;
            num *= arr[i];
            dfs(cnt+1, num);
            num /= arr[i];
            vis[i] = 0;
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    std::ios::sync_with_stdio(false);
    vector<int> vc;
    
    cin >> tc;
    for(int i = 1; i <= tc; i++){
        int w, p, answer = 0;
        vc.clear();
        cin >> w >> p;
        // 입력
        for(int i = 0; i < w; i++) {
            for(int j = 0; j < w; j++){
                cin >> maps[i][j];
            }
        }
        
        for(int i = 0; i < w - p + 1; i++){
            for(int j = 0; j < w - p + 1; j++){
                for(int k = 0; k < p; k++){
                    for(int t = 0; t < p; t++){
                        answer += maps[i+k][j+t];
                    }
                }
                vc.push_back(answer);
                answer = 0;
            }
        }
        
        sort(vc.begin(), vc.end());
        cout << "#" << i << ' ' << vc[vc.size()-1]  << endl;
        
        
    }
    
}
