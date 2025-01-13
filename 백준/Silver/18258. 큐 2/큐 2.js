const fs = require("fs");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "input.txt")
  .toString()
  .split("\n");
const tc = Number(input[0]);

class Queue {
  constructor() {
    this.data = [];
    this.head = 0;
    this.tail = 0;
  }

  push(value) {
    this.data[this.tail++] = value;
  }

  size() {
    return this.tail - this.head;
  }

  pop() {
    if (this.size() === 0) return -1;
    const value = this.data[this.head];
    this.head++;
    return value;
  }

  front() {
    return this.size() === 0 ? -1 : this.data[this.head];
  }

  back() {
    return this.size() === 0 ? -1 : this.data[this.tail - 1]; // 수정
  }

  empty() {
    return this.size() === 0 ? 1 : 0;
  }
}

let q = new Queue();
let answer = [];

for (let i = 1; i <= tc; i++) { // 반복문 범위 수정
  const [op, num] = input[i].split(" ");

  switch (op) {
    case "push":
      q.push(Number(num));
      break;

    case "pop":
      answer.push(q.pop());
      break;

    case "size":
      answer.push(q.size());
      break;

    case "empty":
      answer.push(q.empty());
      break;

    case "front":
      answer.push(q.front());
      break;

    case "back":
      answer.push(q.back());
      break;
  }
}

// 모든 결과를 한 번에 출력
console.log(answer.join("\n"));