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

    int tc, cnt = 0;
    cin >> tc;
    
    for(int idx = 1; idx <= tc; idx++){
        int son = 1, mom = 1;
        string s;
        cin >> s;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'L'){
                son = son;
                mom = son + mom;
            } else {
                son = son + mom;
                mom = mom;
            }
        }
        
        
        cout << "#" << idx << ' ' << son << ' ' << mom << endl;
    }
        
    return 0;
}
