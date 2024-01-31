#include<iostream>
#include<algorithm>
#include<cstring>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define MAX 1000001
#define INF 9999999
#define MOD 15746
#define ll long long
using namespace std;

int n;
ll dp[MAX];
ll fibo(int n){
    
    ll &ret = dp[n];
    if(ret != -1){
        return ret;
    }
    
    
    ret = fibo(n-1) + fibo(n-2);
    
    return ret % MOD;
    
}

int main()
{
    FASTIO;
    
    cin >> n;
    memset(dp, -1, sizeof dp);
    dp[1] = 1;
    dp[2] = 2;
    
    cout << fibo(n);
    
}

