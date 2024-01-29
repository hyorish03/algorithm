#include<iostream>
#include<algorithm>
#include<cstring>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define MAX 1000001
#define INF 9999999
using namespace std;

int n;
long long dp[MAX];

int main()
{
    FASTIO;
    cin >> n;
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    
    for(int i = 3; i < 91; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n];
}
