#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        
        if(m == 0){
            if(pq.empty()){
                cout << 0 << "\n";
            } else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(m);
        }
    }
    
}

