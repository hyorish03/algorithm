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
tc=10;
    deque<char> kp;
    
    for(int idx = 1; idx <= tc; idx++){
            int idxs;
            cin >> idxs;
        kp.clear();
        string s,finds, keep = "";
        cnt = 0;
        cin >> finds >> s;
        for(int i = 0; i < s.size(); i++){

            kp.push_back(s[i]);
            if(kp.size() == finds.size()){
                for(int i = 0; i < finds.size(); i++){
                    keep += kp[i];
                }
                if(keep == finds){
                    cnt++;
                }
                keep = "";
                kp.pop_front();
            }
        }
        cout << "#" << idx << ' ' << cnt << endl;
    }
        
    return 0;
}
