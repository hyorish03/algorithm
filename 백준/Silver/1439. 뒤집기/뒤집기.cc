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
    
    /* 숫자를 뒤집어서 최소 횟수로 모두 동일한 숫자로 만들어야 됨*/
    // 1 덩어리 갯수
    string s;
    cin >> s;
    int one=0, zero=0;
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] != s[i+1]){
            if(s[i] == '1'){
                one++;
            } else {
                zero++;
            }
        }
    }
    if(s[s.size()-1] == '1'){
        one++;
    }
    
    if(s[s.size()-1] == '0'){
        zero++;
    }
    
    cout << min(one, zero);
    return 0;
}
