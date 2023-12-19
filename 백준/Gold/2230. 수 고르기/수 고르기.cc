#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2000000000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> v(n);
    
    
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
   
    sort(v.begin(), v.end());
    
    
    int st = 0, en = 0;
    
    int mins = MAX;
    int ans = 0;
    
    while( st < n && en < n){
        if(v[en]-v[st] >= m){
            ans = v[en]-v[st];
            mins = min(mins, ans);
            st++;
        } else {
            en++;
        }
    }
    
    cout << mins;
    return 0;
}
