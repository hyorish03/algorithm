function solution(p, l) {
    let arr = p.map((p,index)=>{return{loc:index,prio: p}})
    let q = [];
    
    while(arr.length > 0){
        let front = arr.shift();
        let isHighest = arr.some((a)=> a.prio > front.prio);
        
        if(isHighest){
            arr.push(front);
        }else{
            q.push(front.loc);
        }
    }
    
    return q.findIndex((a)=> a === l)+1;
}