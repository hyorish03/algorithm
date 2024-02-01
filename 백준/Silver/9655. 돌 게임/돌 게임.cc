#include <iostream>
#include <vector>
#include <cstring>
#define MAX 1001
using namespace std;

int dp[MAX];
int dfs(int n){
    int &ret = dp[n];

    if(ret != -1){
        return ret;
    }

    ret = 1+min(dfs(n-1), dfs(n-3));
    return ret;
}


int main(){
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 1;
    
    int ans = dfs(n);
//    cout << ans << ' ';
    if(ans % 2 == 1){
        cout << "SK";
    } else {
        cout << "CY";
    }
}

