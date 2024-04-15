#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000000
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    for(int tc = 1; tc <= t; tc++)
    {
        int person, snack;
        cin >> person >> snack;
        cout << "#" << tc << " " ;
        if(person % snack == 0){
            cout << 0;
        } else {
            cout << 1;
        }
        cout << endl;
    }
    return 0;
}
