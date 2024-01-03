#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1001;

int N; // 단지의 크기
int cnt = 0;
int arr[MAX];
int map[MAX][MAX];
bool visited[MAX][MAX];
queue <pair<int, int>> q;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int BFS(int x, int y) {
	int ret = 0;
	visited[x][y] = true;
	q.push({ x, y });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		//cout << "현재위치: " << x << ", " << y << "\n";
		ret++;
		q.pop();
		for (int i = 0; i < 4; i++) { //상하좌우 탐색
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (ny >= 0 && ny < N && nx >= 0 && nx < N) // 배열의 범위 확인
				if (visited[nx][ny] == 0 && map[nx][ny] == 1) { // 방문 체크가 되었는 지, 배추가 있는 지 확인
					q.push({ nx, ny });
					visited[nx][ny] = true;
				}
		}
	}

	return ret;
}

int main() {
	cin >> N;
	int a;
	
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < N; j++) {
			map[i][j] = input[j] - '0';
		}
	}

	vector<int> ans;
	for(int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && visited[i][j] == 0) {
				ans.push_back(BFS(i, j));
			}
		}
	}

	cout << ans.size()<<"\n";
	sort(ans.begin(), ans.end());
	for (auto x : ans) cout << x << "\n";
}