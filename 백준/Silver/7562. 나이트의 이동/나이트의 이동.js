const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  .filter(Boolean);

let inputIdx = 0;
const tc = Number(input[inputIdx++]);
const dy = [1, 2, 2, 1, -1, -2, -2, -1];
const dx = [-2, -1, 1, 2, -2, -1, 1, 2];

for (let i = 0; i < tc; i++) {
  const width = Number(input[inputIdx++]);

  let vis = Array.from(Array(width), () => Array(width).fill(-1));

  const [stY, stX] = input[inputIdx++].split(" ").map(Number);
  const [desY, desX] = input[inputIdx++].split(" ").map(Number);

  const BFS = (y, x) => {
    let q = [[y, x]];
    vis[y][x] = 0;

    while (q.length > 0) {
      let [curY, curX] = q.shift();

      if (curY === desY && curX === desX) return vis[curY][curX];

      for (let i = 0; i < 8; i++) {
        let ny = curY + dy[i];
        let nx = curX + dx[i];

        if (
          ny >= 0 &&
          nx >= 0 &&
          ny < width &&
          nx < width &&
          vis[ny][nx] === -1
        ) {
          vis[ny][nx] = vis[curY][curX] + 1;
          q.push([ny, nx]);
        }
      }
    }

    return -1;
  };

  console.log(BFS(stY, stX));
}
