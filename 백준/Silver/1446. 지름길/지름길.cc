#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 10001
vector<pair<int, int>> v[MAX];
int main() {
    int n, des;
    cin >> n >> des;

    for(int i = 0; i < n; i++){
        int fr, to, cost;
        cin >> fr >> to >> cost;
        if(to > des || to - fr < cost) continue;
        v[to].push_back({fr, cost});
    }
    vector<int> m(10001, 987654321);
    m[0] = 0;
    
    for(int i = 1; i <= des; i++){
        m[i] = m[i-1]+1;
        for(int j = 0; j < v[i].size(); j++){
            int from = v[i][j].first;
            int cost = v[i][j].second;
            m[i] = min(m[i], m[from] + cost);
        }
    }
    
    cout << m[des];
    return 0;
}
