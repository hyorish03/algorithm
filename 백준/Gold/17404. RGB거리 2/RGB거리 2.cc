#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1001
#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int arr[MAX][3]; // 0행: 1번 집, 1행: 2번 집, 2행: 3번 집
    int dp[MAX][3];
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }

    int ans = INF;
    for(int first = 0; first < 3; first++){
        for(int i = 0; i < 3; i++){
            if(i == first){
                dp[0][i] = arr[0][i];
            } else {
                dp[0][i] = INF;
            }
        }

        for(int i = 1; i < n; i++){
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
        }
        
        for(int i = 0; i < 3; i++){
            if(i == first){
                continue;
            }
            ans = min(ans, dp[n-1][i]);
        }
    }
    
    cout << ans;
    return 0;
}
