#include<iostream>
#include<algorithm>
#include <ctime>
#include <cstring>
#define MAX 5001
#define INF 9999999
using namespace std;
int memo[MAX];
int dp(int n){
    if(n < 3){
        return INF;
    }
    int &ret = memo[n];
    
    if(ret != -1){
        return ret;
    }
    
    return ret = 1 + min(dp(n-3), dp(n-5));
    
    
}
    
int main()
{
    int n;
    cin >> n;
    memset(memo, -1, sizeof memo);

    memo[3] = 1;
    memo[5] = 1;
    
    int ret = dp(n);
    if(ret > INF){
        cout << -1;
    } else {
        cout << ret;
    }
    return 0;
}
