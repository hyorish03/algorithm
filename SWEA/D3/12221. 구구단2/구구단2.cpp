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
    for(int idx = 1; idx <= tc; idx++){
        int n1, n2;
        cin >> n1 >> n2;
        
        cout << "#" << idx << ' ';
        if(n1 >= 10 || n2 >= 10){
            cout << -1 << endl;
            
        } else {
            cout << n1*n2 << endl;
        }
        
       
        
    }
        

    return 0;
}

