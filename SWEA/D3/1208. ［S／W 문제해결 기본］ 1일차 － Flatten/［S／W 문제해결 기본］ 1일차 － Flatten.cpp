#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    priority_queue<int, deque<int>, greater<int>> q;
    for(int i = 1; i <= 10; ++i){
        deque<int> dq;
        int dump, height;
        cin >> dump;
        for(int j = 0; j < 100; j++){
            cin >> height;
            dq.push_back(height);
        }
        
        
        for(int i = 0; i < dump; i++){
            sort(dq.begin(), dq.end());

            int fr = dq.front();
            int bk = dq.back();
            
            dq.pop_back();
            dq.pop_front();
            dq.push_back(bk-1);
            dq.push_back(fr+1);
        }
        sort(dq.begin(), dq.end());

  
        cout << "#" << i << ' ' << dq.back() - dq.front() << endl;
        
        
    }
    return 0;
}

/**
2
5 8 3 1 5 6 9 9 2 2 4
 */
