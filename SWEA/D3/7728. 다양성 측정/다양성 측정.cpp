#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;
vector<int> v;
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    
    for(int idx = 1; idx <= tc; idx++){
        string n;
        cin >> n;
        v.clear();
        for(int i = 0; i < n.size(); i++){
            v.push_back(n[i]-'0');
        }
        
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
   
        cout << "#" << idx << ' '<< v.size() << endl;
    }
        

    return 0;
}

