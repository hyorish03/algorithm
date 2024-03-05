#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end(), greater<int>());
    
    int ans = 0;
    int sum = INF;
    for(int i = 0; i < n; i++){

        int temp = v[i] * (i+1);
        ans = max(ans, temp);
    }
    cout << ans;
    
    return 0;
}
