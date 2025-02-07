#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int main() {
    FASTIO;
    
    int n, maxK;
    cin >> n >> maxK;
    
    vector<int> weight(n + 1);
    vector<int> value(n + 1);
    vector<int> dp(maxK + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int w = maxK; w >= weight[i]; w--) { 
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }

    cout << dp[maxK] << "\n"; 
    
    return 0;
}