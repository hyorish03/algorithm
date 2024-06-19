#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#define MAX 1002
using namespace std;
int h, w, r;
int arr[MAX][MAX];

int main() {
    
    ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int tc;
    int minX = 10001;
    int minY = 10001;
    int maxX = -1;
    int maxY = -1;
    int x, y, w, h;
    
    cin >> tc;
    
    for(int idx = 1; idx <= tc; idx++){
        cin >> x >> y >> w >> h;
        minX = min(minX, x);
        minY = min(minY, y);
        maxX = max(maxX, x+w);
        maxY = max(maxY, y+h);
        
        for(int i = y; i < y+h; i++){
            for(int j = x; j < x+w; j++){
                arr[i][j] = idx;
            }
        }
    }
    
    for(int idx = 1; idx <= tc; idx++){
        int cnt = 0;
        for(int i = minY; i <= maxY; i++){
            for(int j = minX; j <= maxX; j++){
                if(arr[i][j] == idx){
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    
}

    

