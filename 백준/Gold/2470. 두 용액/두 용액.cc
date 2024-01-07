#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
typedef long long ll;

#define MAX 2000000000
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    deque<pair<int, int>> res;
    res.push_back({0, 0});
    ll st = 0, en = n-1, sum = MAX;
    
    while(st < en){
//        cout << v[st] << " + " << v[en] << " = " << v[st]+v[en] << ", " << sum << endl;
        if(abs(v[st]+v[en]) < sum){
//            cout << "HHHHEEEERRRRREEEE" << endl;
            sum = abs(v[st] + v[en]);
            res.pop_front();
            res.push_back({v[st], v[en]});

        }
         
        if(v[st]+v[en] < 0){
            st++;
        } else {
            en--;
        }
    }
    
    
    cout << res[0].first << ' ' << res[0].second;
    

    return 0;
}



