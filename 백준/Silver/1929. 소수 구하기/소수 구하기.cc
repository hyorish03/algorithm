#include <iostream>
#include <vector>
#include <cmath>
#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FASTIO;
    int m, n;
    cin >> m >> n;

    // m과 n 중 작은 값이상의 소수 판별을 위한 배열 생성
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; // 0과 1은 소수가 아님

    for (int i = 2; i <= sqrt(n); ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // m부터 n까지 소수 출력
    for (int i = m; i <= n; ++i) {
        if (isPrime[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}
