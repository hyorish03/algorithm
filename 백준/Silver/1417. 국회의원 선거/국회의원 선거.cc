#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FASTIO;
    int n, ds;
    cin >> n;
    priority_queue<int>pq;
    vector<int> v;
    cin >> ds;
    for(int i = 1; i < n; i++){
        int a;
        cin >> a;
        pq.push(a);
    }

    int res = 0;
    while(!pq.empty() && pq.top() >= ds){
            int temp = pq.top();
            pq.pop();
            pq.push(temp - 1);
            ds += 1;
            
            res++;
        
    }
    cout << res;
    return 0;
}
