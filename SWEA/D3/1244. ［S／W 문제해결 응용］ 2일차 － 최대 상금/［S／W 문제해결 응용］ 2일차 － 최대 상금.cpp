#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

string num;
int ans = 0;
void dfs(int idx, int cnt, int curCnt){
    if(cnt == curCnt){
        ans = max(ans, stoi(num));
        return;
    }
    
    for(int i = idx; i < num.length()-1; i++){
        for( int j = i+1; j < num.length(); j++){
            if(num[i] <= num[j]){
                swap(num[i], num[j]);
                dfs(i, cnt, curCnt+1);
                swap(num[i], num[j]);
            }
            if(i == num.length()-2 && j == num.length() - 1){
                swap(num[i], num[j]);
                dfs(i, cnt, curCnt + 1);
                swap(num[i], num[j]);
            }
        }
    }
    
    return;
}
int main() {
    int t;
    cin >> t;
    
    for(int i = 1; i <= t; ++i){
        int cnt;
        cin >> num >> cnt;
        ans = 0;
        dfs(0, cnt, 0);
        cout << "#" << i << ' '<< ans << '\n';
    }
    return 0;
}

