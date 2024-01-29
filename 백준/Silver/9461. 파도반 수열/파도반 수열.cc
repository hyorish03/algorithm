#include<iostream>
#include<algorithm>
#include<cstring>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define MAX 1000001
#define INF 9999999
using namespace std;

int n;
long long dp[MAX];

vector<int> ans;
vector<int> result;

int main()
{
    FASTIO;
    int a;
    cin >> n;
    
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    
    for(int i = 0; i < n; i++){
        cin >> a;
        
        for(int i = 4; i <= 100; i++){
            dp[i] = dp[i-2] + dp[i-3];
        }
        cout << dp[a] << '\n';
        
    }
}
