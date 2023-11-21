#include <iostream>
#include <algorithm>

#define MAX 101

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    std::ios::sync_with_stdio(false);
    
    int x, y, w, h;
    
    cin >> x >> y >> w >> h;
    int tempx, tempy;
    
    tempx = w - x;
    tempy = h - y;
    
    int ans = min(tempx, tempy);
    ans = min(ans, x);
    ans = min(ans, y);
    cout << ans;
}
