function solution(l, r) {
    var answer = [];
    
    for(let i = l; i <= r; i++){
        let num = i.toString();
        let flag = true;
        for(let n of num){
            if(n !== "5" && n !== "0"){
                flag = false;
                break;
            }
        }
        
        if(flag){
            answer.push(Number(num))
        }
        
    }
    
    return answer.length > 0 ? answer : [-1];
}