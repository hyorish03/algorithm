#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 2000000000
#define MIN 0

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
    
    long st = 1, en = v.back(), ans = 0;
    
    while(st<=en){
        
        long mid = (st+en)/2;
        
        int total = 0;
        for(int i = 0; i < n; i++){
             total += v[i] / mid;
        }
        
        
        if(total >= m){
            ans = max(ans, mid);
            st = mid + 1;

        } else {
            en = mid - 1;
        }
    }
    
    cout << ans;
    
    return 0;
}
