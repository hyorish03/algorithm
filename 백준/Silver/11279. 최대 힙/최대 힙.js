class MaxHeap {
  constructor() {
    this.heap = [];
  }

  getLeftChildIndex = (parentIndex) => parentIndex * 2 + 1;
  getRightChildIndex = (parentIndex) => parentIndex * 2 + 2;
  getParentIndex = (childIndex) => Math.floor((childIndex - 1) / 2);

  push = (key, value) => {
    const node = { key, value };
    this.heap.push(node);
    this.heapifyUp();
  };

  heapifyUp = () => {
    let index = this.heap.length - 1;
    const lastInsertedNode = this.heap[index];

    while (index > 0) {
      const parentIndex = this.getParentIndex(index);

      if (this.heap[parentIndex].key < lastInsertedNode.key) { // 최대 힙: 부모보다 크면 스왑
        this.heap[index] = this.heap[parentIndex];
        index = parentIndex;
      } else break;
    }

    this.heap[index] = lastInsertedNode;
  };

  pop = () => {
    if (this.heap.length === 0) return undefined;
    if (this.heap.length === 1) return this.heap.pop();

    const rootNode = this.heap[0];
    this.heap[0] = this.heap.pop();
    this.heapifyDown();
    return rootNode;
  };

  heapifyDown = () => {
    let index = 0;
    const size = this.heap.length;
    const rootNode = this.heap[index];

    while (this.getLeftChildIndex(index) < size) {
      const leftChildIndex = this.getLeftChildIndex(index);
      const rightChildIndex = this.getRightChildIndex(index);

      const largerChildIndex =
        rightChildIndex < size &&
        this.heap[rightChildIndex].key > this.heap[leftChildIndex].key // 최대 힙: 더 큰 자식 선택
          ? rightChildIndex
          : leftChildIndex;

      if (this.heap[largerChildIndex].key > rootNode.key) { // 최대 힙: 자식이 더 크면 스왑
        this.heap[index] = this.heap[largerChildIndex];
        index = largerChildIndex;
      } else break;
    }

    this.heap[index] = rootNode;
  };

  isEmpty = () => this.heap.length === 0;
}

const fs = require("fs");
const [n, ...rest] = fs.readFileSync(0, "utf8").trim().split("\n");
const pq = new MaxHeap();
const answer = [];

rest.forEach((line) => {
  const number = parseInt(line, 10);
  if (number === 0) {
    answer.push(pq.pop()?.value ?? 0);
  } else {
    pq.push(number, number);
  }
});

console.log(answer.join("\n"));
