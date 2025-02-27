const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "input.txt")
  .toString()
  .split("\n");

class Stack {
  constructor() {
    this.data = [];
    this.tail = 0;
  }

  push(value) {
    this.data[this.tail++] = value;
  }

  pop() {
    if (this.tail > 0) {
      this.tail -= 1;
      return this.data[this.tail];
    } else {
      return -1;
    }
  }
  size() {
    return this.tail;
  }

  last() {
    return this.data[this.tail] ? this.data[this.tail] : false;
  }
}

const tc = Number(input[0]);

let answer = [];
for (let i = 1; i <= tc; i++) {
  let stack = new Stack();
  let flag = false;
  if (input[i].length % 2 !== 0) {
    answer.push("NO");
    flag = true;
    continue;
  }

  let arr = input[i].split("");
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === "(") {
      stack.push(arr[i]);
    } else {
      if (stack.pop() === -1) {
        answer.push("NO");
        flag = true;
        break;
      }
    }
  }
  if (!flag) {
    if (stack.size() > 0) {
      answer.push("NO");
    } else {
      answer.push("YES");
    }
  }
}
console.log(answer.join("\n"));
