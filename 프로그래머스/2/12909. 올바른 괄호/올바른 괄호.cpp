#include<string>
#include<queue>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    queue<int> q;
    for(auto a : s){
        if(a == '('){
            q.push(a);
        }else{
            if(q.empty()){
                answer = false;
                break;
            }else{
                q.pop();
            }
        }  
    }
    
    if(q.size() > 0){
        answer = false;
    }

    return answer;
}