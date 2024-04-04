#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> v;
    int tc;
    cin >> tc;
    for(int idx = 1; idx <= tc; idx++){
        int n, cnt = 0;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        
        for(int i = 0; i < n; i++){
            if(s1[i] != s2[i]){
                cnt++;
            }
        }
        
        cout << "#" << idx << ' ' << n-cnt << endl;
    }
        

    return 0;
}

