function createUndirectedGraph(n, edges) {
  const graph = Array.from({ length: n+1 }, () => []);

  edges.forEach(([node1, node2]) => {
    graph[node1].push(node2);
    graph[node2].push(node1); 
  });

  return graph;
}

function solution(n, edge) {
    const graph = createUndirectedGraph(n, edge)
    const result = bfs(graph, 1)
    return result.length;
}

function bfs(graph, startNode){
    let vis = Array.from(graph.length).fill(false)
    let distance = Array.from(graph.length).fill(-1)
    let queue = [startNode]
    
    vis[startNode] = true;
    distance[startNode] = 0;
    
    while(queue.length > 0){
        let frontNode = queue.shift();
        graph[frontNode].forEach((neigh) => {
            if(!vis[neigh]){
                vis[neigh] = true;
                distance[neigh] = distance[frontNode] + 1;
                queue.push(neigh)
            }
        })
    }
    
    let maxDistance = -1;
    let farthesNode = [];
    
    for(let i = 0; i < distance.length; i++){
        if(distance[i] > maxDistance){
            maxDistance = distance[i];
            farthesNode = [i]; 
        } else if(distance[i] == maxDistance){
            farthesNode.push(i)
        }
    }
    
    return farthesNode
}