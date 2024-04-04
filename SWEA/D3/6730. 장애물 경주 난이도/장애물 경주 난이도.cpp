#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> v;
    int tc;
    cin >> tc;
    for(int i = 1; i <= tc; i++){
        int l, upMax = 0, downMax = 0;
        cin >> l ;
        v.clear();
        for(int j = 0; j < l; j++){
            int n;
            cin >> n;
           
            v.push_back(n);
        }
        for(int j = 0; j < l-1; j++){
            
            if(v[j] < v[j+1]){
                upMax = max(upMax, v[j+1]-v[j]);
            }
            if(v[j] > v[j+1]){
                downMax = max(downMax, v[j] - v[j+1]);
            }
        }
        cout << "#" << i << ' ' << upMax << ' ' << downMax  << endl;
       
        
    }
        

    return 0;
}

