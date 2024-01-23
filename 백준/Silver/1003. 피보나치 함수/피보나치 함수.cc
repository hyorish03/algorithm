
#include <iostream>
#include <set>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int t, n;

pair<long long,long long> dp[41];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    
    while(t--){
        cin >> n;
        
        dp[0].first = 1;
        dp[0].second = 0;
        dp[1].first = 0;
        dp[1].second = 1;
        
        for(int i = 2; i < 41; i++){
            dp[i].first = dp[i-1].first + dp[i-2].first;
            dp[i].second = dp[i-1].second + dp[i-2].second;
            
        }
        cout << dp[n].first <<' ' << dp[n].second<< '\n';
    }
  
    return 0;
}
