function solution(bridgeLength, maxWeight, truckWeights) {
    let time = 0;
    let bridge = Array(bridgeLength).fill(0); // 다리 상태를 나타내는 배열
    let bridgeWeight = 0; // 현재 다리 위에 있는 트럭의 무게 합

    while (truckWeights.length > 0 || bridgeWeight > 0) {
        time++;

        // 다리에서 트럭 이동 (다리 끝에 있는 트럭 제거)
        bridgeWeight -= bridge.shift();

        // 다음 트럭을 다리에 올릴 수 있는지 확인
        if (truckWeights.length > 0 && bridgeWeight + truckWeights[0] <= maxWeight) {
            const nextTruck = truckWeights.shift();
            bridge.push(nextTruck);
            bridgeWeight += nextTruck;
        } else {
            // 다리에 트럭을 올릴 수 없으면 0 추가 (빈 공간 유지)
            bridge.push(0);
        }
    }

    return time;
}