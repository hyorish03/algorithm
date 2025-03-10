let input = require("fs").readFileSync("/dev/stdin").toString().split("\n");
let node = Number(input[0]);
let edge_num = Number(input[1]);
let graph = [...new Array(node + 1)].map(() => []);
let visited = [...new Array(node + 1)].fill(0);
let ans = 0;

for (let i = 0; i < edge_num; i++) {
  let start = Number(input[i + 2].split(" ")[0]);
  let end = Number(input[i + 2].split(" ")[1]);
  graph[start].push(end);
  graph[end].push(start);
}

visited[1] = 1;
function dfs(start) {
  for (let end of graph[start]) {
    if (!visited[end]) {
      visited[end] = 1;
      ans++;
      dfs(end);
    }
  }
}
dfs(1);
console.log(ans);