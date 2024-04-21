#include <iostream>
#define MAX 101
using namespace std;
long long dp[MAX];
int main(){
    int tc;
    cin >> tc;
   
    for(int idx = 1; idx <= tc; idx++){
        int n;
        cin >> n;
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i <= n+3; i++){
            dp[i] = dp[i-3] + dp[i-2];
        }
       cout << "#" << idx << ' ';
        
        cout << dp[n-1];
        cout << '\n';
//        for(int i = 0; i <= n+3; i++){
//            cout << dp[i] << ' ';
//        } cout <<endl;
    }
}
