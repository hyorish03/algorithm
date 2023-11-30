#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAX = 100001;
map<int, int> mp;
int arr[MAX] = {0,};
// a.second : 등장 횟수
// second : 등장 횟수, arr[it->first] : idx

bool sorting(const pair<int,int>& a, const pair<int,int>& b){
    if (a.second == b.second) return arr[a.first] < arr[b.first];
    return a.second > b.second;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    
    cin >> x >> y;
    
    for(int i = 0; i < x; i++){
        int m;
        cin >> m;
        mp[m]++;
        
        if(arr[m] == 0){
            arr[m] = i+1;
        }
       
    }

    vector<pair<int,int>> sortedVec(mp.begin(), mp.end());

    sort(sortedVec.begin(), sortedVec.end(), sorting);
    
    for(auto a : sortedVec){
        for(int i  = 0; i < a.second; i++)
            cout << a.first <<  ' ' ;
    }

    return 0;
}