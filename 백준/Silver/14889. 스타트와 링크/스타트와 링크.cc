#include <iostream>
#include <set>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int sstart = 0, slink = 0;
vector<int> team, rest, match, total, ans;
int arr[20][20];
int vis[20], mvis[20];

void matching (int now, int cnt, int temp){
    if(cnt == 2){
        if(temp == 1){
            sstart += arr[match[0]][match[1]] + arr[match[1]][match[0]];
            
        } else {
            slink += arr[match[0]][match[1]] + arr[match[1]][match[0]];
        }
        return;
    }
    
    for(int i = 0; i < n/2; i++){
        if(temp == 1){
            if(!mvis[i] && now <= team[i]){
                mvis[i] = true;
                match.push_back(team[i]);
                matching(team[i], cnt+1, temp);
                match.pop_back();
                mvis[i] = false;
            }
        } else {
            if(!mvis[i] && now <= rest[i]){
                mvis[i] = true;
                match.push_back(rest[i]);
                matching(rest[i], cnt+1, temp);
                match.pop_back();
                mvis[i] = false;
            }
        }
    }
}

void dfs(int now, int cnt){
    if(cnt == n/2){
        set_difference(total.begin(), total.end(), team.begin(), team.end(), back_inserter(rest));
        matching(team[0], 0, 1);
        matching(rest[0], 0, 0);
        ans.push_back(abs(sstart - slink));
        
        while(!rest.empty()){
            rest.pop_back();
        }

        sstart = 0;
        slink = 0;
        return;
    }
    
    for(int i = 0; i < n; i++){
        if(!vis[i] && now <= i){
            vis[i] = true;
            team.push_back(i);
            dfs(i, cnt+1);
            team.pop_back();
            vis[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        total.push_back(i);
    }
    
    dfs(0,0);
    
    sort(ans.begin(), ans.end());
    cout << ans[0];
    return 0;
}
