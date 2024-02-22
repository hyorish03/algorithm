#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 3001
using namespace std;

int main() {
    // n: 접시 수, d: 초밥 가짓수, k: 연속 접시 수, c: 쿠폰 번호, cnt: 윈도우 내의 종류 수
    int n, d, k, c, inp, cnt = 0;
    cin >> n >> d >> k >> c;
    
    deque<int> window;
    deque<int> sushi;
    int check[MAX] = {0}; // 배열 초기화
    
    for(int i = 0; i < n; i++){
        cin >> inp;
        sushi.push_back(inp);
    }
    
    for(int i = 0; i < k; i++){
        window.push_back(sushi[i]);
        if(check[sushi[i]] == 0){
            cnt++;
        }
        check[sushi[i]] += 1;
    }
    
    int res;
    if(check[c] == 0){
        res = cnt + 1;
    } else {
        res = cnt;
    }
    
    for(int i = 0; i < n-1; i++){
        int front = window.front();
        int next = sushi[(i+k)%n];
        
        if(check[front] == 1){
            cnt -= 1;
        }
        check[front] -= 1;
        
        window.pop_front();
        window.push_back(next);
        
        if(check[next] == 0){
            cnt += 1;
        }
        check[next] += 1;
        
        if(check[c] == 0){
            res = max(res, cnt + 1);
        } else {
            res = max(res, cnt);
        }
    }
    
    cout << res << endl;
}
