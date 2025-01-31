let tg = 0;
let nums = [];
let answer = 0;

function dfs(cur, index, debug) {
    if(index == nums.length - 1){
        // console.log("ㅠㅠ")
        if(cur == tg){
        // console.log("야호 타겟이다")
        answer++;
        return;
    }
        return;
    }

    dfs(cur+nums[index+1], index+1, `${debug} + "+" + ${nums[index+1]}`)
    dfs(cur-nums[index+1], index+1, `${debug} + "-" + ${nums[index+1]}`)
    
}

function solution(numbers, target) {
    tg = target;
    nums = numbers;
    
    dfs(numbers[0], 0, numbers[0]);
    dfs(-numbers[0], 0, -numbers[0]);
    
    return answer;
}