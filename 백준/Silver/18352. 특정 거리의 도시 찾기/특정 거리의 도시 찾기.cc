#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string.h>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX 101
using namespace std;

int n, m, k, x;
vector<vector<int>> v;
vector<int> vis;
vector<int> result;

void bfs() {
    int start = x;
    queue<int> q;
    q.push(start);
    vis[start] = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            if (vis[next] == -1) {
                vis[next] = vis[now] + 1;
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == k) {
            result.push_back(i);
        }
    }
}

int main() {
    FASTIO;
    cin >> n >> m >> k >> x;
    v = vector<vector<int>>(n+1);
    vis = vector<int> (n+1, -1);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
    }

    bfs();

    if (result.size() == 0) cout << -1;
    else {
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << "\n";
    }

    return 0;
}
