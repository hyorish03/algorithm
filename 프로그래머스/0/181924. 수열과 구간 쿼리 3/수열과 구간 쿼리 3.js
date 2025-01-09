function solution(arr, queries) {
    queries.forEach(([a,b])=>{
        [arr[a], arr[b]] = [arr[b], arr[a]] 
    })
    var answer = [];
    
    return arr;
}