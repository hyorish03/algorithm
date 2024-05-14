#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int map[501][501];
    int len = triangle.size();
    for(int i = 0 ; i < triangle.size(); i++){
        for(int j = 0; j < triangle[i].size();j++){
            map[i][j] = triangle[i][j];
        }
    }

    for(int i = len; i >= 0; i--){
        for(int j = 0; j < i; j++){
            int maxes = max(map[i][j], map[i][j+1]);
            map[i-1][j] = map[i-1][j] + maxes;
        }
    }

    int answer = map[0][0];
    return answer;
}