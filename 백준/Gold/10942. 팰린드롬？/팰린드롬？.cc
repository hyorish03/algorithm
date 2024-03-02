#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int arr[2001];
bool p[2001][2001] = { false, };

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n - 1; i++) {
        if (arr[i] == arr[i + 1])
            p[i][i + 1] = true;
    }

    for (int i = 1; i <= n; i++) {
        p[i][i] = true;
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 2; j <= n; j++) {
            if (arr[i] == arr[j] && p[i + 1][j - 1] == true) {
                p[i][j] = true;
            }
        }
    }

    int m, s, e;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        cout << p[s][e] << '\n';
    }

    return 0;
}
