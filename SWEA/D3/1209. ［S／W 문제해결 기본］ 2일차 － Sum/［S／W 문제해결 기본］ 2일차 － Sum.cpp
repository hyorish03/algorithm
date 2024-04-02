#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 101
#define Width 100
int arr[MAX][MAX];
vector<int> v;
void input(){
    for(int j = 0; j < Width; j++){
        for(int k = 0; k < Width; k++){
            cin >> arr[j][k];
        }
    }
}

void calc(){
    int row=0, col=0, dae=0, reDae=0;
    for(int i = 0; i < Width; i++){
        row = 0;
        col = 0;
        for(int j = 0; j < Width; j++){
            row += arr[i][j];
            col += arr[j][i];
        }
//        cout << "row: " << row << endl;
//        cout << "col: " << col << endl;
        v.push_back(row);
        v.push_back(col);
    }
    
    for(int i = 0; i < Width; i++){
        dae += arr[i][i];
        reDae += arr[Width-i][i];
    }
//    cout << "dae: " << dae << endl;
//    cout << "reDae: " << reDae << endl;
    v.push_back(dae);
    v.push_back(reDae);
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;

    for(int i = 1; i <= 10; i++){
        cin >> tc;
        v.clear();
        input();
        calc();
        sort(v.begin(), v.end(), greater<int>());
        cout << "#" << tc << ' ' << v.front() << endl;
    }
        

    return 0;
}
/*
 1
 4 4 3 2 1
 2 2 1 6 5
 3 5 4 6 7
 4 2 5 9 7
 8 1 9 5 6

 */
