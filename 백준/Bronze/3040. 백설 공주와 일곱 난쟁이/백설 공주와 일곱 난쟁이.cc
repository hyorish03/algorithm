#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#define MAX 1002
#define FASTIO  ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr);
using namespace std;
int vis[MAX];
int sum = 0;
vector<int> v;
vector<int> ans;
bool flag = false;
void dfs(int cnt, int cur){
    
    if(cnt == 2){
        if(sum - (ans[0]+ans[1]) == 100){
//            cout << "BREAK" << '\n';
//            cout << ans[0] << ' ' << ans[1] << '\n';

            for(int i = 0; i < v.size(); i++){
                if(v[i] != ans[0] && v[i] != ans[1]){
                    cout << v[i] << '\n';
                }
            }
        }
        return;
    }
    
    for(int i = 0; i < v.size(); i++){
        if(!vis[i] && cur <= v[i]){
            vis[i] = true;
            ans.push_back(v[i]);
            dfs(cnt+1, v[i]);
            vis[i] = false;
            ans.pop_back();
        }
    }
    
    if(flag)
        return;
}
int main() {
    
    FASTIO

    for(int i = 0; i < 9; i++){
        int k;
        cin >> k;
        v.push_back(k);
        sum += k;
    }

    dfs(0, 0);
   
    
}

    

