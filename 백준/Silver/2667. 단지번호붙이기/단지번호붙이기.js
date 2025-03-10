const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "input.txt")
  .toString()
  .trim()
  .split("\n");

const N = Number(input[0]);
const graph = Array.from(Array(N), () => Array(N).fill(0));
let vis = Array.from(Array(N), () => Array(N).fill(false));
for (let i = 0; i < N; i++) {
  graph[i] = input[i + 1].split("").map(Number);
}

let answer = [];
let dy = [0, 0, 1, -1];
let dx = [1, -1, 0, 0];

const BFS = (y, x) => {
  let q = [];
  let cnt = 1;
  q.push({ y, x });
  vis[y][x] = true;
  while (q.length > 0) {
    let { y: curY, x: curX } = q.shift();

    for (let i = 0; i < 4; i++) {
      let ny = curY + dy[i];
      let nx = curX + dx[i];

      if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
        if (!vis[ny][nx] && graph[ny][nx] === 1) {
          vis[ny][nx] = true;
          q.push({ y: ny, x: nx });
          cnt++;
        }
      }
    }
  }

  return cnt;
};

for (let i = 0; i < N; i++) {
  for (let j = 0; j < N; j++) {
    if (!vis[i][j] && graph[i][j] === 1) {
      const res = BFS(i, j);
      answer.push(res);
    }
  }
}
answer.sort((a, b) => a - b);
console.log(answer.length);
console.log(answer.join("\n"));
