let vis; // 방문 배열

function bfs(y, x, n, computers) {
    let q = [];
    q.push(y); // BFS에서 큐에 현재 노드(행)을 추가

    vis[y] = 1; // 해당 노드를 방문 처리

    while (q.length > 0) {
        let cur = q.shift(); // 큐의 첫 번째 원소를 가져옴

        for (let i = 0; i < n; i++) {
            if (computers[cur][i] === 1 && !vis[i]) { // 연결된 노드가 방문되지 않은 경우
                vis[i] = 1; // 방문 처리
                q.push(i);   // 큐에 추가
            }
        }
    }
}

function solution(n, computers) {
    let answer = 0;
    vis = new Array(n).fill(0); // n개의 노드를 방문했는지 확인하기 위한 배열 초기화

    for (let i = 0; i < n; i++) {
        if (!vis[i]) { // 해당 노드를 방문하지 않았다면
            bfs(i, i, n, computers); // BFS 탐색 시작
            answer++; // 하나의 네트워크를 찾았으므로 카운트 증가
        }
    }

    return answer;
}