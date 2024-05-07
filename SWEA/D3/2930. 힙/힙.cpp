#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    for(int idx = 1; idx <= tc; idx++){
        int n;
        cin >> n;
        cout<<'#'<<idx<<' ' ;
        priority_queue<int,vector<int>,less<int>>pq;

        for(int i = 0; i < n; i++){
            int cmd;
            cin >> cmd;
            if(cmd == 1){
                int a;
                cin >> a;
                pq.push(a);
            } else {
                if(pq.empty()) cout << -1 << ' ';
                else {
                    cout << pq.top() << ' ';
                    pq.pop();
                }
            }
        }
        cout<<'\n';
    }
    return 0;
}

