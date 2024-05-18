#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
priority_queue<int,vector<int>, greater<int>> q;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    int cnt = 0;
    for(int i = 0; i < scoville.size(); i++){
        if(scoville[i] == 0) cnt++;
        q.push(scoville[i]);
    }
    if(cnt >= 2 ) return -1;
    else {
    while(1){
        if(q.top() >= K) break;
        if(q.size() < 2) {return -1;}
        int first = q.top();
        q.pop();
        int second = q.top();
        q.pop();
        q.push(first+second*2);
        answer++;

    }
    return answer;
    }
}