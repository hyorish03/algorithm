#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    for(int idx = 1; idx <= tc; idx++){
        cout << "#" << idx << ' ';
        int n;
        string s;
        cin >> n >> s;
        int len = s.size()-1;
        int hoxy = 0;
        for(int i = 0; i <= len; i++){
            hoxy += s[len-i] - '0';
         
        }
        cout << hoxy % (n-1);
        cout << '\n';
    }
}
