#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v;
int s = 1;
int br, yl;
vector<int> answer;

void getHW(){
    int y = 3;
    int x = s / y;
    while (y <= s/2){
        if(s % y == 0){
            x = s / y;
            if(x > 1){
                v.push_back({x, y});
             v.push_back({y, x});

            }
        }
        y += 1;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    for(auto a : v){
        int x = a.first;
        int y = a.second;
        int testB = x * 2 + 2 *(y-2);
        int testY = (x-2)*(y-2);
        if(testB == br && testY == yl && x >= y){
            answer.push_back(x);
            answer.push_back(y);
        }

    }
}
vector<int> solution(int brown, int yellow) {
    s = brown + yellow;
    br = brown;
    yl = yellow;
    int h, w;
    
    getHW();
    return answer;
}