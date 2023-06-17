#include <string>
#include <vector>
#include <utility>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10;
    int right = 12;
    int cntlft, cntrgt = 0;
    
    for(int i = 0; i < numbers.size(); i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += 'L';
            left = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += 'R';
            right = numbers[i];
        }
        else {
            if(numbers[i] == 0)
               numbers[i] = 11;
            
            cntlft = abs((numbers[i] - left) / 3) + abs((numbers[i] - left) % 3);
            cntrgt = abs((numbers[i] - right) / 3) + abs((numbers[i] - right) % 3);
            
            if(cntlft > cntrgt){
               right = numbers[i];
                answer += 'R';
            } else if (cntlft < cntrgt){
                left = numbers[i];
                answer += 'L';
           } else if(cntlft == cntrgt){
                if(hand == "right"){
                     answer += 'R';
                    right = numbers[i];
                }
                else if(hand == "left"){
                    answer += 'L';
                    left = numbers[i];
                    
                }
            }
        }
            
    }
    return answer;
}