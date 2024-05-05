#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    for(int idx = 1; idx <= tc; idx++){
        int n1, n2;
        cin >> n1 >> n2;
        vector<string> v;
        vector<string> v2;
        
        for(int i = 0; i < n1; i++){
            string s;
            cin >> s;
            v.push_back(s);
        }
        
        for(int i = 0; i < n2; i++){
            string s;
            cin >> s;
            v2.push_back(s);
            
        }
        
        sort(v.begin(), v.end());
        sort(v2.begin(), v2.end());
        int cnt = 0, i = 0, j = 0;
           while(i < n1 && j < n2){
               if(v[i] == v2[j]){
                   cnt++;
                   i++;
                   j++;
               }else if(v[i] < v2[j]){
                   i++;
               }else{
                   j++;
               }
           }
        
        cout << "#" << idx << ' ' << cnt;
        cout << '\n';
    }
    return 0;
}

