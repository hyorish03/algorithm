#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    int score[8] = {0, 3, 2, 1, 0, 1, 2, 3};
    map<char, int> m;
    string sur;
    string answer = "";
    int c;
    
    for(int i = 0; i < survey.size(); i++){
        sur = survey[i];
        c = choices[i];
        
         if(c < 4){
            m[sur[0]] += score[c];
         } else if(c >= 4){
            m[sur[1]] += score[c];
         }   
    }
    
   answer += m['R'] >= m['T'] ? 'R' : 'T'; 
   answer += m['C'] >= m['F'] ? 'C' : 'F'; 
   answer += m['J'] >= m['M'] ? 'J' : 'M'; 
   answer += m['A'] >= m['N'] ? 'A' : 'N'; 
        
    
    return answer;
}