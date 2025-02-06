let map;
let vis;
let dy = [0, 0, 1, -1];
let dx = [1, -1, 0, 0];

function bfs(y, x){
    let q = [];
    q.push({y, x})
    vis[y][x] = 1;
    
    while(q.length > 0){
        let cur =  q.shift();
        
        for(let i = 0; i < 4; i++){
            let nextX = cur.x + dx[i];
            let nextY = cur.y + dy[i];

            if(nextX >= 0 && nextX < map[0].length && nextY >= 0 && nextY < map.length && map[nextY][nextX] == 1 ){
                if(vis[nextY][nextX] == 0) {
                    vis[nextY][nextX] = vis[cur.y][cur.x] + 1;    
                    q.push({y: nextY, x: nextX});
                }
                
                
            }
        }
    }
}

function solution(maps) {
    map = maps;
    
    var n = maps.length;  // 행의 개수
    var m = maps[0].length;
    
    vis = Array.from(Array(n), () => new Array(m).fill(0));

    bfs(0,0);
    
    return vis[n-1][m-1] == 0 ? -1 :vis[n-1][m-1];
}