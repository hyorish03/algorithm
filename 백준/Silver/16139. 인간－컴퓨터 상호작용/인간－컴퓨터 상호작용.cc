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
    string s;
    cin >> s;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        char c;
        int a, b, cnt = 0;
        cin >> c >> a >> b;
        
        for(int i = a; i <= b; i++){
            if(s[i] == c){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    
    
    return 0;
}
