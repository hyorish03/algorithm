#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>
#define MAX 1000001
#define FASTIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

double arr[MAX];
int main(){
    FASTIO;
    string str;
    
    getline(cin, str);
   
    int cnt = 0;
    
    for(int i = 0; i < str.size(); i++){
       if(str[i] == ' ')
           cnt ++;
    }
    if(str[0] == ' '){
        cnt -= 1;
    }
    
    if(str[str.size()-1] == ' ')
        cnt -= 1;
    
    cout << cnt + 1;
    return 0;
}


