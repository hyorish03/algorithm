#include <iostream>
#include <vector>
#include <deque> // <--- 덱 헤더 파일
#include <stack>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAX 10000001
using namespace std;

int main() {
    FASTIO;
    int n;
    deque<int> v;
    stack<int> st;
    vector<string> s;
    cin >> n;

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        v.push_back(k);
    }
    
    int idx = 1;
    while (!v.empty()) {
        if (st.empty() || st.top() != v.front()) {
            st.push(idx++);
            s.push_back("+");
        } else {
            v.pop_front();
            st.pop();
            s.push_back("-");
        }
        if (idx > n + 1) break;
    }

    if(!v.empty()){
        cout << "NO";
    } else {
        for(int i = 0; i < s.size(); i++){
            cout << s[i] << '\n';
        }
    }

    return 0;
}
