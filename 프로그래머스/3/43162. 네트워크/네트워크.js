let vis = [];
let q = [];

function bfs(start, coms){
    q.push(start);
    vis[start] = true;
    
    while(q.length > 0){
        let cur = q[0];
        q.shift();
        
        for(let i = 0; i < coms.length; i++){
            if(!vis[i] && coms[cur][i] == 1){
                q.push(i);
                vis[i] = true;
            }
        }
    }
}

function solution(n, computers) {
    var answer = 0;
    vis = Array(n).fill(0);
    for(let i = 0; i < computers.length; i++){
        if(!vis[i]){
            bfs(i, computers);
            answer++;
        }
    }
    return answer;
}