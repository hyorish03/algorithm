#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

int cardNum, ans=0;
int selected, t, num;
int res = 0;
int cnt = 0;
vector<int> v;
vector<int> nums;
bool vis[101] = {0,};


int main() {
    cin.tie(0);
    cout.tie(0);
    std::ios::sync_with_stdio(false);
 
    cin >> cardNum >> selected;
    
    for(int i = 0; i < cardNum; i++){
        cin >> t;
        v.push_back(t);
    }
    
    sort(v.begin(), v.end());

    
    set <string> s;
        do {
            string res;
            for (int i = 0; i < selected; i++) {
                res += to_string(v[i]);
            }
            s.insert(res);
        } while (next_permutation(v.begin(), v.end()));
        cout << s.size();    return 0;
}
