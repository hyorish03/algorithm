#include <iostream>
#include <vector>
using namespace std;
char map[64][64];

bool check(){
    bool flag = true;

    for(int i = 0; i < 8; i++){
        int cntRow = 0;
        int cntCol = 0;
        for(int j = 0; j < 8; j++){
            if(map[i][j] == 'O')
                cntRow++;
            if(map[j][i] == 'O')
                cntCol++;
//            cout << "ROW: " << cntRow << "Col: " << cntCol << endl;
            if(cntRow > 1 || cntCol > 1){
                return false;
            }
        }
    }
    return flag;
}
int main(){
    int tc;
    cin >> tc;
    vector<int> v;
    for(int idx = 1; idx <= tc; idx++){
        int cnt = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                char c;
                cin >> c;
                map[i][j] = c;
                if(c == 'O')
                    cnt++;
            }
        }
        cout << "#" << idx << ' ';
        if(cnt != 8){
            cout << "no";

        } else {
            if(check()){
                cout << "yes";
            } else {
                cout << "no";
            }
        }
        cout << endl;
    }
    return 0;
}

