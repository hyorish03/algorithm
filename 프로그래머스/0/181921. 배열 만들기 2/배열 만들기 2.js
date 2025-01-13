function* gen(){
    let i = 1;
    while(true){
        yield Number(i.toString(2))*5
        i++;
    }
}

function solution(l, r) {
    var answer = [];
    let g = gen();
    
    for(let value of g){
        if(value >= l && value <= r){
            answer.push(value)
        }
        if(value > r) break;
    }
    
    return answer.length > 0 ? answer : [-1];
}