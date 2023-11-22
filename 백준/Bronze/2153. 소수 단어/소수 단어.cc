#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define MAX 101

using namespace std;

int sum = 0;
int ans = 0;
void isPrime(){
    for(int i = 2; i * i <= sum; i++){
        if(sum % i == 0){
            ans++;
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    std::ios::sync_with_stdio(false);
    vector<int> vec;
    string s ;
    
    cin >> s;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            sum += s[i] - 'a' + 1;
        }
        else{
            sum += s[i] - 'A' + 27;
        }
    }
    
    isPrime();
    if(ans != 0)
        cout << "It is not a prime word." << endl;
    else
        cout << "It is a prime word." << endl;
}
