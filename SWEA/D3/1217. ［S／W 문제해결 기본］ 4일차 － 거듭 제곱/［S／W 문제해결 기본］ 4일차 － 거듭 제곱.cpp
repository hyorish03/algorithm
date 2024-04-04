#include <iostream>

using namespace std;
//
//
//int answer(int low, int up){
//    int ans = low;
//    while(up > 1){
//        if(up % 2 == 0) {
//            ans *= ans;
//            up /= 2;
//        } else {
//            ans *= low;
//            up -= 1;
//        }
//        
//    }
//    return ans;
//}

int recur(int low, int up, int ans) {
//    cout << up << ' ' << ans << endl;
    if (up == 1) {
        return ans;
    }
    return recur(low, up - 1, ans * low);
    
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
//    cin >> tc;
    tc = 10;
    for(int idx = 1; idx <= tc; idx++){
        int a, b;
        int t;
        cin >> t;
        cin >> a >> b;
        
        cout << "#" << idx << ' '<< recur(a, b, a) << endl;
    }
        

    return 0;
}

