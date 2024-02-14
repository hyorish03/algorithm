#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAX 10000001
using namespace std;

int main() {
    FASTIO;
    int n;
    string s, str, ans;
    vector<string>sVec;
    bool flag = false;
    cin >> s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        sVec.push_back(str);
    }
    
    
      for (int i = 1; i <= 26; i++) {
          string shifted_s = s;
          for (char& c : shifted_s) {
              c = 'a' + (c - 'a' + i) % 26;
          }
          
          bool found = false;
          for (const string& str : sVec) {
              if (shifted_s.find(str) != string::npos) {
                  found = true;
                  break;
              }
          }
          
          if (found) {
              cout << shifted_s << endl;
              break;
          }
      }
    
    
    
    return 0;
}
