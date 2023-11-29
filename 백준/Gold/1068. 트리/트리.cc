#include <iostream>
#include <vector>

using namespace std;

const int MAX = 101;

vector<int> vec[MAX];
bool vis[MAX];
int n, root, d, leaf;

void dfs(int curNode) {
    if (vis[curNode]) {
        return;
    }

    vis[curNode] = true;

    if (vec[curNode].empty() || vec[curNode].size() == 1 && vec[curNode][0] == d) {
        leaf++;
    }

    for (int i = 0; i < vec[curNode].size(); i++) {
        int nextNode = vec[curNode][i];
        if (nextNode != d) {
            dfs(nextNode);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;

        if (m == -1) {
            root = i; // Fix the assignment to root
        } else {
            vec[m].push_back(i);
        }
    }

    cin >> d;

    if (d == root) {
        cout << 0;
    } else {
        dfs(root);
        cout << leaf;
    }

    return 0;
}
