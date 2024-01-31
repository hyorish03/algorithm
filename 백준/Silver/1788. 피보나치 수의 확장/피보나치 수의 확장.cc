#include<iostream>
#include<algorithm>
#include<cstring>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define MAX 1000001
#define INF 9999999
#define MOD 1000000000
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
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    if( n < 0 ){
        if(abs(n) % 2 == 0){
            cout << -1 << '\n';
            cout << fibo(abs(n));
        } else {
            cout << 1 << '\n';
            cout << fibo(abs(n));
        }
    } else if (n == 0){
        cout << 0 << '\n';
        cout << fibo(n);
    } else if (n > 0){
        cout << 1 << '\n';
        cout << fibo(n);
    }
}
