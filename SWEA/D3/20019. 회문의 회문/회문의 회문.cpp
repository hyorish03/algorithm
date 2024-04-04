#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    for(int idx = 1; idx <= tc; idx++){
        string s, keep;
        cin >> s;
        keep = s;
        
        reverse(s.begin(),s.end());
        cout << "#" << idx << ' ';

        if(s == keep){
            string s1 = keep.substr(0, keep.size()/2);
            string s2 = keep.substr(keep.size()/2+1, keep.size());
            if(s1 == s2){
                cout <<"YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else {
            cout << "NO"<<endl;
        }
    }
        

    return 0;
}
