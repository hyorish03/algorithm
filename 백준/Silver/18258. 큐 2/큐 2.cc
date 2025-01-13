#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define FASTIO  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define INTMAX 1000000001
using namespace std;

int main() {
    FASTIO;
    queue<int> q;
    
    int tc;
    cin >> tc;
    
    for(int i = 0; i < tc; i++){
        string op;
        int num;
        
        cin >> op;
        
        if(op == "push"){
            cin >> num;
            q.push(num);
        }
        
        if(op == "pop"){
            if(q.size() == 0) {cout << -1 << '\n';}
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        
        if(op == "size"){
            cout << q.size() << '\n';
        }
        
        if(op == "empty"){
            cout << q.empty()<< '\n';
        }
        
        if(op == "front"){
            if(q.size() == 0) {cout << -1 << '\n';}
            else {
                cout << q.front()<< '\n';
            }
        }
        
        if(op == "back"){
            if(q.size() == 0) {cout << -1 << '\n';}
            else {
                cout << q.back()<< '\n';
            }
        }
        
    }
   
    return 0;
}
