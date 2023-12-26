#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

#define MAX 2000000000
#define MIN 0

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    vector<int> v(n);
    vector<int> lion;
    deque<int> dq;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(x == 1) lion.push_back(i);
        
    }

    if(lion.size() < m){
        cout << -1 << endl;
        return 0;
    }
    
    int ans = MAX;
    
    for(int i = 0; i <= lion.size() - m; i++){
        ans = min(ans, lion[i+m-1] - lion[i] + 1);
    }
    cout << ans;

    return 0;
}
