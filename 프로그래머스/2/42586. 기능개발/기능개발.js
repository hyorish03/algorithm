function solution(progresses, speeds) {
    var answer = [];
    var pro = progresses;
    var spd = speeds;
    var temp = [];
    
    for(let i = 0; i < pro.length; i++){
        temp[i] = Math.ceil((100 - pro[i])/spd[i]); 
    }
    var max = temp[0];
    var cnt = 1;
    
    console.log("temp", temp);
    for(let i = 1; i < temp.length; i++){
        console.log('max', max, 'temp', temp[i]);
        
        if(temp[i] > max){
            console.log('cnt', cnt);
            answer.push(cnt);
            max = temp[i];
            cnt = 0;
        }
        cnt++;
    }
    answer.push(cnt);

    return answer;
}