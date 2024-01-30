#include<iostream>
#include<algorithm>
#include<cstring>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define MAX 1000001
#define INF 9999999
using namespace std;

int n;
int dp[MAX];
int main()
{
    FASTIO;
    cin >> n;
    
    memset(dp, -1, sizeof dp);
    
    dp[1] = 1;
    dp[2] = 3;
    
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2] * 2) % 10007;
    }
    
    cout << dp[n];
    
}
