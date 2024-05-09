#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    for(int idx = 1; idx <= tc; idx++){
        cout << "#" << idx << ' ';
        int a, b, c , d;
        cin >> a >> b >> c >> d;
        
        int ans = min(b,d)-max(a,c);
        if(ans <= 0) cout << 0;
        else cout << ans;
        cout << '\n';
    }
}
