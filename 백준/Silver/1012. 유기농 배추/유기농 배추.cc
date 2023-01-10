#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int N, M, T, C; // N = 배추밭의 가로길이, M = 배추밭의 새로길이, T = 테스트케이스, C = 배추의 수
const int MAX = 1001;
int map[MAX][MAX] = { 0, };
bool visited[MAX][MAX] = { 0, };
int cnt = 0;
queue<pair<int,int>> q;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void BFS(int x, int y) {
	visited[x][y] = true;
	q.push({x, y});

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		//cout << "현재위치: " << x << ", " << y << "\n";
		q.pop();
		for (int i = 0; i < 4; i++) { //상하좌우 탐색
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (visited[nx][ny] == 0 && map[nx][ny] == 1) {
				q.push({nx, ny});
				visited[nx][ny] = true;
			}
		}
	}
}

int main() {
	cin >> T;

	while (T--) {
		int cnt = 0;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));

		cin >> N >> M >> C;
		for (int i = 0; i < C; i++) {
			int a, b;// a는 행 b는 열
			cin >> a >> b;
			map[a][b] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0) {
					BFS(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
}