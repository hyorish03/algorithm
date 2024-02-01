#include <iostream>
#include <vector>
#include <cstring>
#define MAX 1001
#define FASTIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

//int dp[MAX];
//int dfs(int n){
//    int &ret = dp[n];
//
//    if(ret != -1){
//        return ret;
//    }
//
//    ret = 1+min(dfs(n-1), dfs(n-3));
//    return ret;
//}
//

int main(){
    FASTIO;
    int n;
    cin >> n;
   
    if(n % 2 == 1){
        cout << "SK";
    } else {
        cout << "CY";
    }
}

