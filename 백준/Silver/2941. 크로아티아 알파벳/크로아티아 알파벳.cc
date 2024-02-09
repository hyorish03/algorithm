#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>  // sort 함수 사용을 위해 추가
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAX 1001
using namespace std;

int main() {
    FASTIO;

    string arr[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    
    string s;
    cin >> s;
    int cnt = 0, slen = 0, idx;
    for(int i = 0; i < 8; i++){
        while(1){
            idx = s.find(arr[i]);
            if(idx == string::npos){
                break;
            } else {
                s.replace(idx, arr[i].size(), "#");
            }
        }
    }
    
//    cout << s.size() << ' ' << s  << cnt << '\n';
    cout << s.size();
    
}



