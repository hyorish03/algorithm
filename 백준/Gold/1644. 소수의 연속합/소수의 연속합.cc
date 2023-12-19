#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 2000000000
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<bool> v(n+1, true);
    vector<int> v2;
    
    for(int i = 1; i*i <= n; i++){
        if(i == 1){
            v[1] = false;
        }else if(v[i]){
            for(int k = i*i; k <= n; k += i){
                v[k] = false;
            }
        }
    }
    
    for (int i = 2; i < v.size(); i++) {
        if(v[i]){
            v2.push_back(i);
        };
    }
    
//    deque<int> test;
//    test.push_back(v2[0]);
    int st = 0, en = 0, cnt = 0;
    int sum;
    if(n == 1){
        cout << 0;
    } else {
        
        sum = v2[0];
        
        while(en < v2.size()){
            if(sum < n){
                en++;
                sum += v2[en];
                //            test.push_back(v2[en]);
            }
            if(sum == n){
                //            for(auto a : test){
                //                cout << a << ' ';
                //            }
                
                cnt++;
                sum -= v2[st];
                //            test.pop_front();
                st++;
                //            cout << endl;
            }
            if(sum > n){
                sum -= v2[st];
                //            test.pop_front();
                st++;
            }
        }
        
        cout << cnt;
    }
    return 0;
}
