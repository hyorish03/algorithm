#include<iostream>
#include <algorithm>
#define MAX 1005
using namespace std;

int dp[MAX][3];

int main()
{
    int n;
    int r[MAX], g[MAX], b[MAX];
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> r[i] >> g[i] >> b[i];
    }
    
    dp[0][0] = r[0];
    dp[0][1] = g[0];
    dp[0][2] = b[0];
    
    for(int i = 1; i < n; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + r[i];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + g[i];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + b[i];
    }
   
    int maxe = *min_element(dp[n-1], dp[n-1]+3);
    cout << maxe;
        
    return 0;
}
