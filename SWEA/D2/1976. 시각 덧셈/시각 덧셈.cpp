#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#define max 101

using namespace std;
int tc, total, n, m;
bool vis[10000001] = {0,};
vector<int> ans;
vector<int> arr;

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
    
    
    cin >> tc;
    for(int i = 1; i <= tc; i++){
        
            int h1, h2, m1, m2, th, tm;;
            cin >> h1 >> m1 >> h2 >> m2;
            th = h1 + h2;
            tm = m1 + m2;
            if(tm >= 60){
                tm -= 60;
                th += 1;
            }
            if(th > 12){
                th -= 12;
            }
            cout << "#" << i << ' ' << th << ' ' << tm << endl;
        
        
    }
    
}
