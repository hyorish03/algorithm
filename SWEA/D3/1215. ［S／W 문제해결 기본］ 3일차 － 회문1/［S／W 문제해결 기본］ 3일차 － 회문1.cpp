#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
using namespace std;
char arr[10][10];

int len;
bool checkPaline(string s){
    int st = 0, cnt = 0, en = s.size()-1;
    while(st<en){
        if(s[st] == s[en]){
            cnt++;
        }
        st++;
        en--;
    }

    if(cnt == s.size()/2){
//        cout << "TRUE: " << s << endl;
        return true;
    } else {
//        cout << "FALSE: " << s << endl;
        return false;
    }
    
}
int ans = 0;
void calc(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8-len+1; j++){
            string strRow = "";
            string strCol = "";
            for(int k = j; k < j+len; k++){
                strRow += arr[i][k];
                strCol += arr[k][i];
            }
//            cout << strRow << ' ' << checkPaline(strRow) << endl;
//            cout << strCol << ' ' << checkPaline(strCol) << endl;

            if(checkPaline(strRow)){
                ans++;
            }
            if(checkPaline(strCol)){
                ans++;
            }
        }
//        cout << "+++++"<<endl;
    }
}
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int idx = 1; idx <= 10; idx++){
        cin >> len;
        ans = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                cin >> arr[i][j];
            }
        }

        calc();
        
        cout << "#" << idx << ' ' << ans;
        cout << endl;
    }
        

    return 0;
}

//5
//cbcabbac
//bbabccba
//abcbccca
//baccaabb
//bcbcacbc
//cabacacb
//caaaccab
//cbabacac
