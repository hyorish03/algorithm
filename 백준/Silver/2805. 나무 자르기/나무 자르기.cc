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
    
    int start = 0;
    int end = *max_element(v.begin(), v.end());
    long long total = 0;
    int ans = 0;
    
    while(start <= end){
        int mid = (start + end) / 2;
        
        total = 0;
        
        for(int i = 0; i < n; i++){
            if(v[i] > mid)
                total += v[i] - mid;
        }
        
        if (total >= m) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    cout << ans;
    
    return 0;
}
