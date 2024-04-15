#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define MAX 1001

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for(int test_case = 1; test_case <= T; ++test_case) {
        vector<int> v(7);
        for(int i = 0; i < 7; i++) {
            cin >> v[i];
        }

        // 중복을 허용하지 않는 set을 사용하여 모든 합을 저장
        set<int, greater<int>> sums;
        for(int i = 0; i < 7; i++) {
            for(int j = i + 1; j < 7; j++) {
                for(int k = j + 1; k < 7; k++) {
                    sums.insert(v[i] + v[j] + v[k]);
                }
            }
        }

        // set의 특성을 활용하여 5번째로 큰 합을 찾음
        auto it = sums.begin();
        advance(it, 4); // 첫 번째 원소에서 시작하여 4번 이동하여 5번째 원소에 접근
        cout << "#" << test_case << ' ' << *it << '\n';
    }
    return 0;
}