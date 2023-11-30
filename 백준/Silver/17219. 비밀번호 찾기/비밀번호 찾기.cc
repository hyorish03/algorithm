#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAX = 10001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
        
    int n, m;
    
    map<string, string> mp;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        string s, t;
        cin >> s >> t;
        
        mp[s] = t;
    }
    
    for(int i = 0; i < m; i++){
        string r;
        cin >> r;
        
        cout << mp.find(r)->second << endl;
    }
    return 0;
}
