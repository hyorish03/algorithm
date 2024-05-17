#include <string>
#include <vector>
#include <iostream>
using namespace std;
int answer = 0;
vector<int> n;

int t;
void dfs(int cnt, int cur){
    if(cnt == n.size()){
        if(t == cur) {answer++;}
        
        return;
    }
    dfs(cnt+1, cur+n[cnt]);
    dfs(cnt+1, cur-n[cnt]);
    
}

int solution(vector<int> numbers, int target) {
    n = numbers;
    t = target;
    dfs(0,0);
    return answer;
}