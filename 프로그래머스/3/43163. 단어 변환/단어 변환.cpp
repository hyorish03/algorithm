#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
unordered_map <string ,int> vis;
vector<string> v;
string st, des;

bool isConnected(string a, string b){
    int cnt = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == b[i]) cnt++;
    }
    
    return cnt == a.size()-1 ? true : false;
}
void bfs(string begin, string target){
    queue<string> q;
    q.push(begin);
    vis[begin] = 1;
    while(!q.empty()){
        string str = q.front();
        q.pop();
        
        for(auto word : v){
            if(!vis[word] && isConnected(str, word)){
                q.push(word);
                vis[word] = vis[str]+1; 
            }
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
    v = words;
    st = begin;
    des = target;
    
    int answer = -1;
    if(find(words.begin(), words.end(), target) == words.end()){
       return 0;
    } else {
        bfs(begin, target);
        return vis[target] - 1;
    }

}
