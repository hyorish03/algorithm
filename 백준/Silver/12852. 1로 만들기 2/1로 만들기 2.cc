#include<iostream>
#include<algorithm>
#include<cstring>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define MAX 1000001
#define INF 9999999
using namespace std;

int n;
int dp[MAX];

vector<int> ans;
vector<int> result;


int dfs(int n){
    ans.push_back(n);

    if(n < 1) return INF;
    int &ret = dp[n];
    if(ret != -1){
        return ret;
    }
   
    if(n % 3 == 0){
        if(n % 2 == 0){
            ret = 1 + min(min(dfs(n/3), dfs(n/2)), dfs(n-1));
        } else {
            ret = 1 + min(dfs(n/3), dfs(n-1));
        }
    } else if ( n % 2 == 0){
        ret = 1 + min(dfs(n-1), dfs(n/2));
    } else {
        ret = 1 + dfs(n-1);
    }
    
    return ret;
}

int main()
{
    FASTIO;
    
    cin >> n;
    memset(dp, -1, sizeof(dp));

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    
    
    int res = dfs(n);
    if(res >= INF){
    } else {
        cout  << res << '\n';
    }

    while (n != 0) {
            cout << n << " ";
            if (dp[n] == dp[n - 1] + 1) {
                n = n - 1;
            }
            else if (n%2 == 0 && dp[n] == dp[n / 2] + 1) {
                n = n / 2;
            }
            else if (n%3 == 0 && dp[n] == dp[n / 3] + 1) {
                n = n / 3;
            }
        }
}
