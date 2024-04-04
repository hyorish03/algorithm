#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc, width;
    tc = 10;
    for(int idx = 1; idx <= tc; idx++){
        int n = 8;
        cin >> width;
        deque<int> q;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            q.push_back(a);
        }
        int minus = 1;
        while(1){
            int temp = q.front()-minus;
            if(temp <= 0) {
                q.push_back(0);
                q.pop_front();
                break;
            }
        
            q.push_back(temp);
            q.pop_front();
            if(minus == 5) minus = 1;
            else minus++;
//            for(int i = 0; i < q.size(); i++)
//            {
//                cout << q[i] << ' ';
//            }cout << endl;
//            
            if(q.back() == 0) break;
        }
       
        cout << "#" << idx << ' ';
        while(!q.empty()){
            cout << q.front() << ' ';
            q.pop_front();
        }
        cout << endl;
    }
        
    return 0;
}

/*
7
1 0 2 0 1 0 1
0 2 0 0 0 0 0
0 0 1 0 0 1 0
0 0 0 0 1 2 2
0 0 0 0 0 1 0
0 0 2 1 0 2 1
0 0 1 2 2 0 2
*/
