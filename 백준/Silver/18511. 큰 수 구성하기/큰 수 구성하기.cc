#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int max_num;
int n, t, num;
int res = 0;
vector<int> v;

void dfs(int num, int ten){
    
    if(num > max_num){
        return;
    }
    
    res = max(res, num);
    
    for(int i = 0; i < v.size(); i++){
        dfs(num+v[i]*ten, ten*10);
    }
    
}

int main() {
    cin.tie(0);
    cout.tie(0);
    std::ios::sync_with_stdio(false);
 
    cin >> max_num >> n;
    
    for(int i = 0; i < n; i++){
        cin >> t;
        v.push_back(t);
    }
    
    sort(v.rbegin(), v.rend());
    
    dfs(0,1);
    
    cout << res << endl;
    
    return 0;
}
