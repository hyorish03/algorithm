#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 100001

using namespace std;
int st, en;
int visited[MAX];
vector<int> ans;
queue<int> q;

void bfs(int st){
    visited[st] = 0;
    q.push(st);
  
    
    while(!q.empty()){
        st = q.front();
        q.pop();
        
        if(st == en){
            return;
        }
        
        if(st + 1 < MAX && visited[st+1] == false){
            visited[st+1] = visited[st] + 1;
            q.push(st+1);
        }
        
        if(st - 1 >= 0 && visited[st-1] == false){
            visited[st-1] = visited[st] + 1;
            q.push(st-1);
        }
        
        if(st * 2 < MAX && visited[st * 2] == false){
            visited[st * 2] = visited[st] + 1;
            q.push(st * 2);
        }
    }
}

int main() {
    cin >> st >> en;
    
    bfs(st);
    
    cout << visited[en];
}
