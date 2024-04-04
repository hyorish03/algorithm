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
        string s;
        cin >> s;
        int cnt = 0;
        int memory[50] = {0,};

        for(int i = 0; i < s.size(); i++){
            if(s[i] - '0' != memory[i]){
                cnt++;
                for(int j = i; j < s.size(); j++){
                    memory[j] = s[i] - '0';
                }
            }
        }
        
        cout << "#" << idx << ' ' << cnt << endl;
    }
        

    return 0;
}

