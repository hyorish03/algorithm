#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
using namespace std;

int main() {
    vector<int> v;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc, width;
//    tc = 10;
    cin >> tc;
    for(int idx = 1; idx <= tc; idx++){
        string s;
        cin >> s;
        cout << "#" << idx << ' ';
        if(s == "MON") cout << 6;
        if(s == "TUE") cout << 5;
        if(s == "WED") cout << 4;
        if(s == "THU") cout << 3;
        if(s == "FRI") cout << 2;
        if(s == "SAT") cout << 1;
        if(s == "SUN") cout << 7;
        
        cout << endl;
    }
        
    return 0;
}

