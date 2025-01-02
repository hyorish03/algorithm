function solution(my_string) {
    let answer = [];
    const AZaz = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'
    answer.length = 52
    answer.fill(0);
    
    my_string.trim().split("").forEach((s)=>{
        answer[AZaz.indexOf(s)]++
    })
    return answer;
}

// function solution(m) {
//     var answer = [];
//     let al = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
//     let a = [];
//     a.length = 52;
//     a.fill(0);

//     m.split("").map((n)=>{
//         a[al.indexOf(n)]+=1
//     })

//     return a;
// }
