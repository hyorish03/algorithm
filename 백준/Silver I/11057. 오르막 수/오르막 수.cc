#include <iostream>
#include <vector>
using namespace std;

const int MOD = 10007;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> dp(N + 1, vector<int>(10, 0));

    for (int i = 0; i <= 9; ++i) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= j; ++k) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }


    int result = 0;
    for (int i = 0; i <= 9; ++i) {
        result = (result + dp[N][i]) % MOD;
    }

    cout << result << endl;

    return 0;
}
