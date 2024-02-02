#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>  // sort 함수 사용을 위해 추가

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAX 1010

using namespace std;
int n;
int arr[MAX];
int dp[MAX];

int main() {
    FASTIO;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    int ans = 0;
    
    for(int i = 1; i <= n; i++){
        dp[i] = 1;
        for(int j = i - 1; j >= 1; j--){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(dp[i], ans);
    }
    cout << ans;
    return 0;
}
