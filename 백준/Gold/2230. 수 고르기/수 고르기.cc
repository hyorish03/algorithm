#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2000000000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    int start = 0;
    int end = 0;
    int answer = MAX;
    
    while(start < n &&  end < n){
        int result = v[end]-v[start];
        
        if(result < m){
            end++;
        } else {
            answer = min(answer, result);
            start++;
        }
    }
    
    cout << answer;
   return 0;
}
