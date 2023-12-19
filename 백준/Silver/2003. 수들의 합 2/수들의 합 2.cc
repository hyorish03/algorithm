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
   
    
    int st = 0, en = 0;
    
    int ans = 0;
    int sum = v[0];

    while (en < n) {
        if(sum == m){
            ans++;
            sum -= v[st];
            st++;
        }
        if(sum < m) {
            en++;
            sum += v[en];
        }
        if(sum > m){
            sum -= v[st];
            st++;
        }
    }

    cout << ans << endl;
    return 0;
}
