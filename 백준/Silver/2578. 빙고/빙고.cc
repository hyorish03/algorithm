#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>  // sort 함수 사용을 위해 추가
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAX 1001
using namespace std;

int arr[5][5];

bool isBingo(){
    int bingoLine = 0;
    
    // 가로 줄 확인
    int checkRow = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(arr[i][j] == 0){
                checkRow++;
            }
        }
        if(checkRow == 5){
            bingoLine++;
        }
        checkRow = 0;
    }
    
    // 세로 줄 확인
    int checkCol = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(arr[j][i] == 0){
                checkCol++;
            }
        }
        if(checkCol == 5){
            bingoLine++;
        }
        checkCol = 0;
    }
    
    // 정대각선 확인
    int dae = 0;
    for(int i = 0; i < 5; i++){
        if(arr[i][i] == 0){
            dae++;
        }
    }
    if(dae == 5){
        bingoLine++;
        dae = 0;
    }
    
    
    // 역대각선 확인
    int rdae = 0;
    for(int i = 0; i < 5; i++){
        if(arr[i][4-i] == 0){
            rdae++;
        }
    }
    if(rdae == 5){
        bingoLine++;
        rdae = 0;
    }
    
    if(bingoLine >= 3){
        return true;
    } else {
        bingoLine = 0;
        return false;
    }
}

int main() {
    FASTIO;
    int n, cnt = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> arr[i][j];
        }
    }
    for(int k = 0; k < 25; k++){
        cin >> n;
        cnt = k+1;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(arr[i][j] == n){
                    arr[i][j] = 0;
                }
                if(k > 10){
                    if(isBingo()){
                        cout << k + 1;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}



