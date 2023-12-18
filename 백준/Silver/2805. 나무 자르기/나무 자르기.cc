#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<int>());

    int left = 0;
    int right = v[0];
    int ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        long long total = 0;

        for (int i = 0; i < N; i++) {
            if (v[i] > mid) {
                total += v[i] - mid;
            } else {
                break;
            }
        }

        if (total >= M) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << endl;
   return 0;
}
