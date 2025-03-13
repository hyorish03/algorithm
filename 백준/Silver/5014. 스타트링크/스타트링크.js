const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.on("line", (input) => {
  const [Total, Start, Des, U, D] = input.split(" ").map(Number);
  const vis = Array(Total + 1).fill(-1); // Use -1 to indicate unvisited
  const dx = [U, -D];

  const BFS = (cur) => {
    let q = [cur];
    vis[cur] = 0;

    while (q.length > 0) {
      let cur = q.shift();

      for (let i = 0; i < 2; i++) {
        let next = cur + dx[i];
        if (next > 0 && next <= Total && vis[next] === -1) {
          vis[next] = vis[cur] + 1;
          q.push(next);
        }
      }
    }
  };

  if (Start === Des) {
    console.log(0);
  } else {
    BFS(Start);
    console.log(vis[Des] !== -1 ? vis[Des] : "use the stairs");
  }

  rl.close();
});
