#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 10001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    deque <int> d;
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        string s;
        
        cin >> s;
        
        if(s == "push_back"){
            int n;
            cin >> n;
            
            d.push_back(n);
            continue;
        }
        if(s == "push_front"){
            int n;
            cin >> n;
            
            d.push_front(n);
            continue;
            
        }
        if(s == "front"){
            if(d.empty()){
                cout << -1 << endl;
            }else {
                cout << d.front()<<endl;
                
            }
            continue;
        }
        if(s == "back"){
            if(d.empty()){
                cout << -1 << endl;
            }else {
                cout << d.back()<<endl;
            }
            continue;
            
        }
        if(s == "size"){
            cout << d.size()<<endl;
            continue;
        }
        if(s == "empty"){
            cout << d.empty()<<endl;
            continue;
            
        }
        if(s == "pop_front"){
            if(d.empty()){
                cout << -1 << endl;
            }else {
                cout << d.front() <<endl;
                d.pop_front();
            }
            continue;
        }
        if(s == "pop_back"){
            if(d.empty()){
                cout << -1 << endl;
            }else {
                cout << d.back() <<endl;
                d.pop_back();
            }
            
            continue;
            
        }
    }
    
}
