#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#define MAX 301
using namespace std;
int h, w, r;
int arr[MAX][MAX];

void rotate(int box){
    for(int i = 0; i < box; i++){
        int leftDown = arr[h-1-i][i];
        int rightUp = arr[i][w-1-i];
        int rightDown = arr[h-i-1][w-i-1];
        
        for(int j = h-2-i; j >= i ; j--) {
            arr[j+1][i] = arr[j][i];
        }
        for(int j = w-i-1; j > i ; j--) {
            arr[h-1-i][j] = arr[h-1-i][j-1];
        }
        for(int j = i; j < h-i-1; j++) {
            arr[j][w-i-1] = arr[j+1][w-i-1];
        }
        for(int j = i; j <= w-2-i; j++) {
            arr[i][j] = arr[i][j+1];
        }
        
        arr[i][w-i-2] = rightUp;
        arr[h-i-2][w-i-1] = rightDown;
        arr[h-1-i][i+1] = leftDown;

    }
}

int main() {
    
    ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    cin >> h >> w >> r;
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> arr[i][j];
        }
    }
    
    int box = min(h,w)/2;
    
    for(int i = 0; i < r; i++){
        rotate(box);
    }
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << arr[i][j] << ' ';
        } cout << '\n';
    }
    
}

    

