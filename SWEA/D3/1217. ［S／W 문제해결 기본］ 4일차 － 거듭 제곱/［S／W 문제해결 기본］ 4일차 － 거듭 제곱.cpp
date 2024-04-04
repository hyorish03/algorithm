#include <iostream>

using namespace std;


int answer(int low, int up){
    int ans = 1;
    while(up > 0){
        if(up % 2 == 1) {
            ans *= low;
        }
        low *= low;
        up /= 2;
//        cout << ans << ' ' << up << endl;
    }
    return ans;
}
//
//int recur(int low, int up, int ans) {
////    cout << up << ' ' << ans << endl;
//    if (up == 1) {
//        return ans;
//    }
//    return recur(low, up - 1, ans * low);
//
//}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
//    cin >> tc;
    tc = 1;
    for(int idx = 1; idx <= 10; idx++){
        int a, b;
        int t;
        cin >> t;
        cin >> a >> b;
        
        cout << "#" << idx << ' '<< answer(a, b) << endl;
    }
        

    return 0;
}

