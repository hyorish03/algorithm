#include <iostream>
#include <cstring>
#define MAX_SIZE 100
#define INF 0x7fffffff

using namespace std;
int n, k, d;
int dy[] = { 0, -1, 1, 0 };
int dx[] = { 1, 0, 0, -1 };

bool board[51][51] = { 0, };
bool visited[51][51] = { 0, };

void DFS(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int ax = x + dx[i];
		int ay = y + dy[i];

		if (ax < 0 || ay < 0 || ax >= n || ay >= k)
			continue;
		if (!board[ax][ay] || visited[ax][ay])
			continue;

		DFS(ax, ay);
	}
}

int main() {
	std::ios::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> k >> d;

		for (int i = 0; i < d; i++)
		{
			int x, y;
			cin >> x >> y;
			board[x][y] = true;
		}

		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				if (board[i][j] == 1 && !visited[i][j])
				{
					count++;
					DFS(i, j);
				}
			}
		}

		cout << count << '\n';
		memset(board, 0, sizeof(board));
		memset(visited, 0, sizeof(visited));
	}

}