#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
using namespace std;
 
int main()
{
    int test_case;
    int T;
 
    cin>>T;
 
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n,q;
        cin >> n >> q;
//        vector<int> v;
        int v[MAX] = {0,};
        
        for(int i = 1; i <= q; i++){
            int l, r;
            cin >> l >> r;
            for(int j = l; j <= r; j++){
                v[j] = i;
            }
        }
        
        cout << "#" << test_case << ' ';
        for(int i = 1; i <= n; i++){
            cout << v[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
