#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int n, w, row, maxi;
    vector<int> v;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> w;
        v.push_back(w);
    }
    cin >> row;
    
    sort(v.begin(), v.end());
    
    int end = v.back();
    int result, sum;
    int start = 0;
    
    while(start <= end){
        sum=0;
        
        int mid = (start+end)/2;
        
        for(auto i=0; i<n;i++) {
            sum += min(v[i],mid);
        }
        if(row>=sum) {
            result=mid;
            start=mid+1;
        }else {
            end=mid-1;
        }
    }
    
    cout << start-1 ;
    
}
