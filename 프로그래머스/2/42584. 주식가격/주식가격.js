function solution(prices) {
    var answer = Array(prices.length).fill(-1)
    console.log(answer)
    for(let i = 0; i < prices.length; i++){
        let curPrice = prices[i];
        let time = 0;
        // console.log("가격:", curPrice, "현재 index:" , i)
        for(let j = i+1; j < prices.length; j++){
            // console.log("비교 가격:" , prices[j], "index: " , j);
            if(prices[j] < curPrice){
                answer[i] = ++time;
                // console.log("현재 가격은 ", time, "초 동안 오르지 않습니다.")
                // console.log("---------------------------------------")
                time = 0;
                break;
            } else {
                time++;
            }
        }
        if(answer[i] == -1){
            // console.log("현재 가격은 ", time, "초 동안 오르지 않습니다.")
            // console.log("---------------------------------------")
            answer[i] = time;
            time = 0;
        }
    }

    return answer;
}