
#include <iostream>
#include <set>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 10000001
using namespace std;

int t, n;

int dp[MAX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    
    while(t--){
        cin >> n;
        
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        
        for(int i = 4; i < 11; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        cout << dp[n] << '\n';
    }
  
    return 0;
}
