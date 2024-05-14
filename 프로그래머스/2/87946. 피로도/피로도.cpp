#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int>> v;
vector<vector<int>> temp;
vector<int> ans;
int vis[10];
int gk;
int answer = -1;
void dfs(int cur, int cnt){
    if(cnt == v.size()){
        int curK = gk;
        int count = 0;
        for(int i = 0; i < temp.size(); i++){
            if(curK >= temp[i][0]){
                curK -= temp[i][1];
                count++;
            }
        }
        answer = max(answer, count);
        return;
    }
    
    for(int i = 0; i < v.size(); i++){
        if(!vis[i]){
            vis[i] = true;
            temp.push_back(v[i]);
            dfs(i, cnt+1);
            vis[i] = false;
            temp.pop_back();
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {

    gk = k;
    v = dungeons;
    dfs(0,0);
    
    for(auto a : ans){
        cout << a << ' ';
    }
    return answer;
}