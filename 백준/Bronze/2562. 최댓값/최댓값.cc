#include <iostream>
#include <vector>
#include <string>

using namespace std;
int arr[9] = {0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int result=0, tmp = 0;
    for(int i = 0; i < 9; i++){
        cin >> arr[i];
    }
    
    for(int i = 0; i < 9; i++){
        if(tmp < arr[i]){
            tmp = arr[i];
            result = i;
        }
    }
    cout << tmp << ' ' << result+1;
    
}
