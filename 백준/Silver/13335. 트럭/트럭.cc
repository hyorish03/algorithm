#include <iostream>
#include <vector>
#include <queue>
#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FASTIO;
    int n, l, w; // 트럭수, 다리 길이, 감당가능무게
    cin >> n >> l >> w;
    
    vector<int> v(n);
    queue<int> q; // 현재 다리 위에 있는 트럭의 큐
    
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    int time = 0; // 경과 시간
    int curWeight = 0; // 현재 다리 위의 트럭 무게 합
    
    for(int i = 0; i < n; i++){
        while(true) {
            if(q.size() == l) { // 다리의 길이에 도달한 경우
                curWeight -= q.front(); // 맨 앞의 트럭을 제거하고 무게 갱신
                q.pop();
            } else {
                if(curWeight + v[i] <= w) { // 다음 트럭이 다리에 진입 가능한 경우
                    q.push(v[i]); // 트럭을 다리에 추가
                    curWeight += v[i]; // 현재 다리 위의 트럭 무게 갱신
                    time++; // 시간 증가
                    break; // 다음 트럭으로 이동
                } else { // 다음 트럭이 다리에 진입할 수 없는 경우
                    q.push(0); // 빈 트럭 추가하여 다리를 유지
                    time++; // 시간 증가
                }
            }
        }
    }
    
    // 마지막 트럭이 다리를 완전히 건너는 시간 계산
    time += l;
    
    cout << time;

    return 0;
}
