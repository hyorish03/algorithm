#include <iostream>
#include <queue>
using namespace std;

int V, E; // V =  정점의 수, E = 간선의 수
const int MAX = 1001;
int map[MAX][MAX] = { 0, };
bool visited[MAX] = { 0, };
int cnt = 0;
queue<int> q;

void BFS(int v) {
	visited[v] = true;
	q.push(v);

	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (int i = 1; i <= V; i++) {
			if (visited[i] == 0 && map[v][i] == 1) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}
int main() {
	int a, b;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	
	for (int i = 1; i <= V; i++) {
		if (visited[i] == 0) {
			BFS(i);
			cnt++;
		}
	}

	cout << cnt;
}