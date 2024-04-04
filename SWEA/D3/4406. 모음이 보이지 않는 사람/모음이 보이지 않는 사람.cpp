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
        string s, ans ="";
        cin >> s;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                continue;
            } else {
                ans+=s[i];
            }
        }
        cout << "#" << idx << ' ' << ans << endl;
       
        
    }
        

    return 0;
}

