#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> p, vector<int> s) {
    vector<int> answer;
    vector<int> temp;

    // 남은 작업량 계산
    for (int i = 0; i < p.size(); i++) {
        int result = ceil(static_cast<double>(100 - p[i]) / s[i]);
        temp.push_back(result);
    }

    // 배포 그룹 계산
    int max = temp.front();
    int cnt = 1;

    for (int i = 1; i < temp.size(); i++) {
        if (temp[i] > max) {
            max = temp[i];
            answer.push_back(cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }
    answer.push_back(cnt);

    return answer;
}

int main() {
    vector<int> p = {93, 30, 55};  // 진행률
    vector<int> s = {1, 30, 5};    // 속도
    vector<int> result = solution(p, s);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}