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
    vector<int> a(n);
    vector<int> b(n);
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>());
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i] * b[i];
    }
    cout << sum;
    return 0;
}
