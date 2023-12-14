#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t, a, b;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> a >> b;

        vector<int> v(a);
        vector<int> v2(b);

        for (int j = 0; j < a; j++) {
            cin >> v[j];
        }

        for (int j = 0; j < b; j++) {
            cin >> v2[j];
        }

        sort(v.begin(), v.end());
        sort(v2.begin(), v2.end());

        int ans = 0;
        int j = 0, k = 0;

        while (j < a && k < b) {
            if (v[j] > v2[k]) {
                ans += (a - j);
                k++;
            } else {
                j++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
