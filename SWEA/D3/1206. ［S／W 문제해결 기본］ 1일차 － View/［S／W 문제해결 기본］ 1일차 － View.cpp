#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

static bool comp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first > b.first;
    }
    return a.second > b.second;
}

int main() {

    for (int idx = 1; idx <= 10; idx++) {
        vector<int> v;
        v.push_back(0);
        v.push_back(0);
        int n;
        cin >> n;
        
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            v.push_back(a);
        }
        v.push_back(0);
        v.push_back(0);
        
        deque<int> dq;
        int ans = 0;
        for(int i = 0; i < n+4; i++){
            dq.push_back(v[i]);
            if(dq.size() == 5){
                int cnt = 0;
                int mid = dq[2];
                int temp = 0;

//                for(int i = 0; i < 5; i++){
//                        cout << dq[i] << ' ';
//                }cout << endl;
                int max = -1;
                for(int i = 0; i < 5; i++){
                    if(mid > dq[i]){
                        if(max < dq[i]){
                            max = dq[i];
                        }
                        cnt++;
                    }
                }
                
                if(cnt == 4){
                    temp = mid - max;

//                    cout <<"Temp: "<< temp << " max: " << max << endl;
                    ans += temp;
                }
                dq.pop_front();
            }
        }
        
        cout << "#" << idx << ' ' << ans<<  endl;
    }
    return 0;
}
/**
1
10
3 5 2 4 9 0 6 4 0 6
 */
