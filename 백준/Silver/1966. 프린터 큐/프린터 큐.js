const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "input.txt")
  .toString()
  .split("\n");

const tc = Number(input[0]);

// 문서의 갯수 N, 몇 번쨰로 인쇄되었는지 궁금한 문서 ㅏ현재 몇 번째에 놓여져 있는지 M
// N개 문서의 중요도

let answer = [];
for (let i = 1; i <= tc * 2; i += 2) {
  const [N, M] = input[i].split(" ");
  if (Number(N) === 1) {
    answer.push(1);
    continue;
  }
  const arr = input[i + 1]
    .split(" ")
    .map((n, index) => ({ value: Number(n), idx: index }));

  let cnt = 0;
  while (true) {
    let maxNum = Math.max(...arr.map((obj) => obj.value));
    let front = arr.shift();
    if (front.value === maxNum) {
      cnt++;
      if (front.idx === Number(M)) {
        answer.push(cnt);
        break;
      }
    } else {
      arr.push(front);
    }
  }
}
console.log(answer.join("\n"));
