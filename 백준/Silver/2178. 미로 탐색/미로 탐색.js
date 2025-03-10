const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "input.txt")
  .toString()
  .trim()
  .split("\n");

const [H, W] = input[0].split(" ").map(Number);
let graph = Array.from(Array(H), () => Array(W).fill(0));
let vis = Array.from(Array(H), () => Array(W).fill(0));
let dy = [0, 0, 1, -1];
let dx = [1, -1, 0, 0];

for (let i = 0; i < H; i++) {
  graph[i] = input[i + 1].split("").map(Number);
}

const BFS = (y, x) => {
  let q = [];
  q.push({ y, x });
  vis[y][x] = 1;

  while (q.length > 0) {
    let { y: curY, x: curX } = q.shift();
    for (let i = 0; i < 4; i++) {
      let ny = curY + dy[i];
      let nx = curX + dx[i];

      if (ny >= 0 && nx >= 0 && ny < H && nx < W) {
        if (!vis[ny][nx] && graph[ny][nx] === 1) {
          vis[ny][nx] = vis[curY][curX] + 1;
          q.push({ y: ny, x: nx });
        }
      }
    }
  }
};
BFS(0, 0);
console.log(vis[H - 1][W - 1]);
