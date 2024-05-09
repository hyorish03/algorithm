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
        string s, copy;
        cin >> s;
        int st = 0, en = s.size()-1;
        bool flag = true;
        while(st <= en){
            if(s[st] == s[en]){
                st ++;
                en --;
            } else if(s[st] == '*' || s[en] == '*'){
                break;
            } else {
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "Exist";
        } else {
            cout << "Not exist";
        }
        cout << '\n';
    }
}
