#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

const int MAX = 100001;
int visited[MAX] = { 0, };
int map[MAX] = { 0, };

int bfs(int start, int end) {
	queue <int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		int here = q.front();
		int cnt = visited[here];
		q.pop();

		if (here == end) {
			return cnt;
		}

		if (  here + 1 < MAX && visited[here + 1] == 0) {
			visited[here + 1] = cnt + 1;
			q.push(here + 1);
		}

		if ( here - 1 > 0 && visited[here - 1] == 0) {
			visited[here - 1] = cnt + 1;
			q.push(here - 1);
		}

		if ( here * 2 < MAX && visited[here * 2] == 0 ) {
			visited[here * 2] = cnt + 1;
			q.push(here * 2);
		}
	}
}

int main() {
	int N, K; // N: 수빈이가 있는 위치, K ; 동생이 있는 위치
	cin >> N >> K;

	if (N > K)
		cout << N - K << "\n";
	else
		cout << bfs(N, K) - 1 << "\n";
}
