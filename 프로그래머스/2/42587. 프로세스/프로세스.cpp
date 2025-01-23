#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;


/** 
    1. p 오름차순 정렬
    2. q 생성
    3. q 루프 돌면서 p랑 비교
        3-1. 만일 p보다 q의 prio가 작다면 q에서 꺼내서 뒤로 보냄 (cnt++)
        3-2. 만일 p랑 q의 prio이 동일하다면 l과 q의 loc비교
            3-2-1. l과 q의 loc가 같다면 return cnt;
            3-2-2. l과 q의 loc가 다르다면 p에서 꺼내서 뒤로 보냄 (cnt++)
        
*/

struct E {
    int loc;
    int prio;
};

int solution(vector<int> pr, int l) {
    queue<E> q;
    deque <int> p;
    
    
    for(int i = 0; i < pr.size(); i++){
        p.push_back(pr[i]);
        q.push({i, p[i]});
    }
    
    sort(p.begin(),p.end(), greater<>()); // 우선순위 내림차순 정렬

    int cnt = 1;
    int loop = 0;
    while(!q.empty()){
        E Elem = q.front();
        int Eloc = Elem.loc;
        int Eprio = Elem.prio;
        q.pop();
        cout << "pfront: " << p.front() << ", {" << Eprio << ", " << Eloc << "}" <<'\n';
        if(p.front() > Eprio){
            q.push(Elem);
        } else if(p.front() == Eprio){
            if(l == Eloc){
                cout << "=======STOP=====" << '\n';
                cout << "pfront: " << p.front() << ", {" << Eprio << ", " << Eloc << "}" <<'\n';
                cout << "=======STOP=====" << '\n';
                return cnt;
            } else {
                cnt++;
                q.push(Elem);
                p.pop_front();
            }
        }
    }
    
    return cnt;
}
