#include <iostream>
#include <queue>
#include <string.h>
#define max  1001

using namespace std;
int N, M, V; // N : 정점의 수, M : 간선의 수, V : 시점

queue<int> q;
bool visited[max];
int map[max][max];

void DFS(int here) {
	cout << here << " ";

	visited[here] = 1;
	for (int next = 1; next <= N; next++) {
		if (map[here][next] && !visited[next])
			DFS(next);
	}
}

void BFS(int here) {

	visited[here] = true;

	q.push(here);
	while (!q.empty()) {
		here = q.front();
		cout << here << " ";

		q.pop();
		for (int next = 1; next <= N; next++) {
			if (visited[next] == 0 && map[here][next] == 1) {
				q.push(next);
				visited[next] = true;
			}
		}

	}
}

int main() {

	cin >> N >> M >> V;

	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	DFS(V);
	cout << "\n";
	memset(visited, 0, sizeof(visited));
	BFS(V);
}