#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
#define MAX 100007
using namespace std;
vector<int> v;
int dp[MAX];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    
    for(int idx = 1; idx <= tc; idx++){
        cout << "#" << idx << ' ';
        int n;
        cin >> n;
        v.clear();
        memset(dp, 0, sizeof dp);
        
        for(int i = 0; i < n; i++){
            int k;
            cin >> k;
            v.push_back(k);
        }
        dp[0] = v[0];
        for(int i = 1; i < n; i++){
            dp[i] = max(dp[i-1] + v[i], v[i]);
        }

        // 최대값 찾기 (여기서는 dp[n-1]이 최대값이지만, 일반적인 경우 최대값을 찾기 위해 다음 코드 사용)
        int max_sum = dp[0];
        for(int i = 1; i < n; i++){
            if(max_sum < dp[i]){
                max_sum = dp[i];
            }
        }
        
        cout << max_sum;
        cout << '\n';
    }
}
