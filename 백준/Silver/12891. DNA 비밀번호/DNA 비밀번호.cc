#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 2000000000
#define MIN 0

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    deque<char> dq;
    string s;
    int n, m, a, c, g, t, aa = 0, cc = 0, gg = 0, tt = 0;
    cin >> n >> m >> s;
    cin >> a >> c >> g >> t;
    
    int st = 0, en = 0, ans = 0;
    
    dq.push_back(s[0]);
    
    if(s[0] == 'A'){
        aa++;
    }
    if(s[0] == 'C'){
        cc++;
    }
    if(s[0] == 'G'){
        gg++;
    }
    if(s[0] == 'T'){
        tt++;
    }
    
    while(en < n){
//        for(auto a : dq){
//            cout << a << ' ';
//        }

//        cout << aa << cc << gg << tt << endl;
        if(dq.size() == m){
            
            if(aa >= a && cc >= c && gg >= g && tt >= t){
                ans++;
//                for(auto a : dq){
//                    cout << a << ' ';
//                }
//                cout << ans << endl;
//                aa = 0;
//                cc = 0;
//                gg = 0;
//                tt = 0;
            }
            st++;
            if(dq[0] == 'A'){
                aa--;
            }
            if(dq.front() == 'C'){
                cc--;
            }
            if(dq.front() == 'G'){
                gg--;
            }
            if(dq.front() == 'T'){
                tt--;
            }
            dq.pop_front();

        } else {
            en++;
            dq.push_back(s[en]);
            if(s[en] == 'A'){
                aa++;
            }
            if(s[en] == 'C'){
                cc++;
            }
            if(s[en] == 'G'){
                gg++;
            }
            if(s[en] == 'T'){
                tt++;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
