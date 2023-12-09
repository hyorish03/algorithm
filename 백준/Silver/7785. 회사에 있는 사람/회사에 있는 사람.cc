#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAX = 10001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
        
    map<string, pair<string, bool>> mp;
    vector<string> v;
    
    int n;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        string s, t;
        cin >> s >> t;
        if(t == "enter"){
            mp[s].first=t;
            mp[s].second = true;
        }
        else {
            mp[s].second = false;
        }
    }
    
    for(auto it = mp.begin(); it != mp.end(); it++){
          if(it->second.second)
              v.push_back(it->first);
    }
    
    sort(v.begin(), v.end(), greater<string>());
    
    for(auto ve : v){
        cout << ve << '\n';
    }
}
