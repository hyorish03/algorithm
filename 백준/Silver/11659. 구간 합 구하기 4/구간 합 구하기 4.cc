#include <iostream>
using namespace std;

int s[100001];
int n, m, a;
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a;
        s[i] = s[i-1] + a;
    }
    
    for(int i = 1; i <= m; i++){
        int st, en;
        cin >> st >> en;
        cout << s[en] - s[st-1] << '\n';
    }
    return 0;
}
