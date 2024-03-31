#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

static bool comp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first > b.first;
    }
    return a.second > b.second;
}

int main() {
    int t;
    cin >> t;
    for (int idx = 1; idx <= t; idx++) {
        map<int, int> mp;
        int n;
        int i;
        cin >> i;
        for(int i = 0; i < 1000; i++) {
            cin >> n;
            
            mp[n]++;
        }
        vector<pair<int, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), comp);

//        for(auto a : v){
//            cout << a.first << ' ' << a.second << endl;
//        }
        cout << "#" << idx << ' ' << v.front().first << endl;
    }
    return 0;
}
