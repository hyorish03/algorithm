#include <string>
#include <vector>
#include <map>

using namespace std;
int score[8] = {0, 3, 2, 1, 0, 1,2, 3};
string solution(vector<string> survey, vector<int> choices) {
    map<char, int> m;
        string answer = "";

    for(int i = 0; i < survey.size(); i++){
        string sur = survey[i];
        int ans = choices[i];
        
        m[sur[ans/4]] += score[ans];
    }
    
    answer += m['R'] >= m['T'] ? "R"  :"T";
    answer += m['C'] >= m['F'] ? "C"  :"F";
    answer += m['J'] >= m['M'] ? "J"  :"M";
    answer += m['A'] >= m['N'] ? "A"  :"N";
    
    
    return answer;
}