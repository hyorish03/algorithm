#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#define MAX 1001
using namespace std;

int main()
{
    int test_case;
    int T;
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;
        
        if(n <= 81){
            bool flag = false;
            for(int i = 1; i <= 9; i++){
                if(n % i == 0 && n / i <= 9){
                    flag = true;
                    cout << "#" << test_case << ' ' << "Yes" << endl;
                    break;
                }
                
            }
            if(!flag){
                cout << "#" << test_case << ' ' << "No" << endl;
            }
        } else {
            cout <<"#" << test_case << ' '<< "No" << endl;
        }

    }
    return 0;
}
