#include<iostream>
#include<algorithm>
#include<cstring>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define MAX 1000001
#define INF 9999999
using namespace std;

int n;
long long dp[MAX];

long long dfs(long long n){
    long long &ret = dp[n];
    
    if(ret != -1){
        return ret;
    }
        
   ret = dfs(n-1) + dfs(n-2);
    return ret;}

int main()
{
    FASTIO;
    cin >> n;
    
    memset(dp, -1, sizeof dp);
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    
    if(n < 3){
        cout << dp[n];
    } else {
        long long ret = dfs(n);
        cout << ret;
    }
}
