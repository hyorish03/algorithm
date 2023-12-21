#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 2000000000
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    deque<char> v2;
    
    string s;
    cin >> s;
    
    
    int a, c, g, t;
    int ans = 0, st = 0, en = 0;

    int ca = 0, cc = 0, cg = 0, ct = 0; // v2에 넣은 알파벳의 갯수 세기 위한 변수
    cin >> a >> c >> g >> t;
    
        v2.push_back(s[0]);
        if(s[0] == 'A')
            ca += 1;
        if(s[0] == 'C')
            cc += 1;
        if(s[0] == 'G')
            cg += 1;
        if(s[0] == 'T')
            ct += 1;
        
        while (en < n){            
            if(v2.size() == m){
                if(ca >= a && cc >= c && cg >= g && ct >= t){
                    ans++;
                }
                
                if(s[st] == 'A')
                    ca -= 1;
                if(s[st] == 'C')
                    cc -= 1;
                if(s[st] == 'G')
                    cg -= 1;
                if(s[st] == 'T')
                    ct -= 1;
                
                v2.pop_front();
                st++;
            } else {
                en++;
                v2.push_back(s[en]);
                if(s[en] == 'A')
                    ca += 1;
                if(s[en] == 'C')
                    cc += 1;
                if(s[en] == 'G')
                    cg += 1;
                if(s[en] == 'T')
                    ct += 1;
            }
        }
        
        cout << ans;
    
    return 0;
}