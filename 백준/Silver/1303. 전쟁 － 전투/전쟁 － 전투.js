const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "input.txt")
  .toString()
  .trim()
  .split("\n");

const [w, h] = input[0].split(" ").map(Number);
const graph = Array.from(Array(h), () => Array(w).fill(0));
let vis = Array.from(Array(h), () => Array(w).fill(false));
const dx = [0, 0, 1, -1];
const dy = [1, -1, 0, 0];

for (let i = 0; i < h; i++) {
  graph[i] = input[i + 1].split("");
}

function BFS(stY, stX, char) {
  let q = [];
  q.push({ y: stY, x: stX, char });
  vis[stY][stX] = true;

  let cnt = 1;

  while (q.length > 0) {
    const { y: curY, x: curX, char } = q.shift();

    for (let i = 0; i < 4; i++) {
      let ny = curY + dy[i];
      let nx = curX + dx[i];

      if (ny >= 0 && nx >= 0 && ny < h && nx < w) {
        if (!vis[ny][nx] && graph[ny][nx] == char) {
          q.push({ y: ny, x: nx, char });
          vis[ny][nx] = true;
          cnt++;
        }
      }
    }
  }
  return cnt;
}

// function DFS(stY, stX, char) {
//   vis[stY][stX] = true;

//   for (let i = 0; i < 4; i++) {
//     let ny = curY + dy[i];
//     let nx = curX + dx[i];

//     if (ny >= 0 && nx >= 0 && ny < h && nx < w) {
//       if (!vis[ny][nx] && graph[ny][nx] == char) {
//         DFS(ny, nx, char);
//         console.log("{", ny, ", ", nx, "}");
//         vis[ny][nx] = true;
//         cnt++;
//       }
//     }
//   }
// }

let cntW = 0;
let cntB = 0;

for (let i = 0; i < h; i++) {
  for (let j = 0; j < w; j++) {
    if (!vis[i][j]) {
      const res = BFS(i, j, graph[i][j]);
      if (graph[i][j] === "W") {
        // console.log("W", res);
        cntW += res * res;
      } else {
        // console.log("B", res);
        cntB += res * res;
      }
    }
  }
}

console.log(cntW, cntB);
