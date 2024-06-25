#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int col[16];
int n, ans = 0;

/*
 퀸을 놓을 수 없는 경우
 1. 동일한 행/열 일 때
 2. 대각선에 퀸이 있을 때
 */

bool check(int lev){
    for(int i = 0; i < lev; i++){
        if(col[i] == col[lev] || abs(col[lev] - col[i]) == lev - i){
            return false;
        }
    }
    return true;

}

void getNQUEEN(int x){
    if(x == n) {
        ans++;
        return;
    }
    
    for(int i = 0; i < n; i++){
        col[x] = i;
        if(check(x)){
            getNQUEEN(x+1);
        }
    }
}

int main(){
    cin >> n;

    getNQUEEN(0);
    
    cout << ans;
    

}
