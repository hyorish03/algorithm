let dy = [0, 0, 1, -1];  // 상하좌우 이동을 위한 배열
let dx = [1, -1, 0, 0];

function bfs(map, vis, n, m) {
    let q = [];
    q.push({ y: 0, x: 0 }); // 시작점 (0,0)
    vis[0][0] = 1; // 시작 위치 방문 표시 (1부터 시작)

    while (q.length > 0) {
        let cur = q.shift();  // 큐에서 좌표 꺼내기

        for (let i = 0; i < 4; i++) {
            let nextX = cur.x + dx[i];
            let nextY = cur.y + dy[i];

            // 범위 체크 + 벽이 아닐 때만 이동 가능
            if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && map[nextY][nextX] == 1) {
                if (vis[nextY][nextX] === 0) { // 방문하지 않은 곳이라면
                    vis[nextY][nextX] = vis[cur.y][cur.x] + 1;  // 이전 거리 +1
                    q.push({ y: nextY, x: nextX }); // 다음 탐색 좌표 추가
                }
            }
        }
    }
}

function solution(maps) {
    let n = maps.length;  // 행의 개수
    let m = maps[0].length; // 열의 개수

    let vis = Array.from(Array(n), () => new Array(m).fill(0)); // `N x M` 크기의 방문 배열

    bfs(maps, vis, n, m); // BFS 실행

    let answer = vis[n - 1][m - 1];  // 도착점의 값 확인

    return answer === 0 ? -1 : answer;  // 도착할 수 없으면 -1 반환
}