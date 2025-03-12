const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  .filter(Boolean);

let inputIdx = 0;
const tc = Number(input[inputIdx++]);

let dy = [0, 1, 0, -1];
let dx = [-1, 0, 1, 0];
let answer = [];
for (let i = 0; i < tc; i++) {
  const [W, H, K] = input[inputIdx++].split(" ").map(Number);

  let vis = Array.from(Array(H + 1), () => Array(W).fill(0));
  let graph = Array.from(Array(H + 1), () => Array(W).fill(0));

  for (let j = 0; j < K; j++) {
    const [x, y] = input[inputIdx++].split(" ").map(Number);
    graph[y][x] = 1;
  }

  const BFS = (y, x) => {
    let q = [{ y, x }];
    vis[y][x] = true;

    while (q.length > 0) {
      const { y: curY, x: curX } = q.shift();

      for (let i = 0; i < 4; i++) {
        let ny = curY + dy[i];
        let nx = curX + dx[i];

        if (ny >= 0 && nx >= 0 && ny < H && nx < W) {
          if (!vis[ny][nx] && graph[ny][nx] === 1) {
            vis[ny][nx] = true;
            q.push({ y: ny, x: nx });
          }
        }
      }
    }
  };

  let cnt = 0;
  for (let i = 0; i < H; i++) {
    for (let j = 0; j < W; j++) {
      if (!vis[i][j] && graph[i][j] === 1) {
        BFS(i, j);
        cnt++;
      }
    }
  }
  answer.push(cnt);
}

console.log(answer.join("\n"));
