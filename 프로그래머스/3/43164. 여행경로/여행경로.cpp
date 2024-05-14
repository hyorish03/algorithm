#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<string>> t;
vector<string> answer, path;
bool vis[10001] = {0,};

void dfs(string st){
    if(path.size() == t.size()+1){
        if(answer.empty() ) {
            answer = path;
        }
        path.pop_back();
        return;
    }
    
    for(int i = 0; i < t.size(); i++){
        if(!vis[i] && t[i][0] == st){
            vis[i] = true;
            path.push_back(t[i][1]);
            dfs(t[i][1]);
            vis[i] = false;
        }
    }
    path.pop_back();
}


vector<string> solution(vector<vector<string>> tickets) {
    t = tickets;
    sort(t.begin(), t.end()); 
    path.push_back("ICN");
    dfs("ICN");
    return answer;
}