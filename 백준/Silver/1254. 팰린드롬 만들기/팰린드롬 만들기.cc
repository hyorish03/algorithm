#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 1001
#define FASTIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

string s;
bool isPal(string s){
    
    for(int i = 0; i < s.size()/2; i++){
        if(s[i] != s[s.size()-1-i])
            return false;
    }
    
    return true;
}

int main(){
    FASTIO;
    int n, ans = 0;
    cin >> s;
    
    ans = s.size() * 2 - 1;
    
    for(int i = 0; i < s.size(); i++){
        string temp = s.substr(i, s.size()-i);
        if(isPal(temp)){
            ans = s.size() + i;
            break;
        }
    }
    
    cout << ans;
}


