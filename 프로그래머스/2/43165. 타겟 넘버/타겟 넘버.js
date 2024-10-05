var ans = 0;
var nums;
var tg;

function dfs(cur, idx, status){

    if(idx === nums.length -1){
        if(cur === tg){
            ans++;
            
        }
        
        return;
    }
    
    dfs(cur+nums[idx+1], idx+1, cur + "+" + nums[idx+1]);
    dfs(cur-nums[idx+1], idx+1, cur + "-" + nums[idx+1]);
    
}
function solution(numbers, target) {
    nums = numbers;
    tg = target;
        
    dfs(0, -1);
    
    return ans;
    
}
