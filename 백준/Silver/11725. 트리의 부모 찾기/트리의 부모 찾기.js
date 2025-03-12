const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  .filter(Boolean);

const N = Number(input[0]); 

let list = Array.from({ length: N + 1 }, () => []);
let vis = Array(N + 1).fill(false);
let par = Array(N + 1).fill(0);

for (let i = 1; i < N; i++) {
  const [a, b] = input[i].split(" ").map(Number);
  list[a].push(b);
  list[b].push(a);
}

const DFS = (node) => {
  vis[node] = true; // 방문 처리

  for (const next of list[node]) {
    if (vis[next]) continue; // 방문한 노드 건너뛰기

    par[next] = node; // 부모 설정
    DFS(next); // 재귀 호출
  }
};

DFS(1); // 루트 노드부터 탐색 시작

console.log(par.slice(2).join("\n"));