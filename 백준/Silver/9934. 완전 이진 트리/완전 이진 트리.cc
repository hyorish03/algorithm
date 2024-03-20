#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
//vector<int> v(10024);
int v[10024];
vector<int> arr[10024];
int n;
int sqr = 1;
void recursive(int d, int st, int en){
    if(st >= en){
        return;
    }
    
    int mid = (st+en)/2;
    arr[d].push_back(v[mid]);
    recursive(d+1, st, mid);
    recursive(d+1, mid+1, en);
}

int main() {
    cin >> n;

    int num;
    int idx = 0;
    while (cin >> num) {
            v[idx++] = num;
    }
    recursive(0,0,idx);
    
    for(int i = 0; i < n; i++){
        for(auto o : arr[i]){
            cout << o << ' ';
        }cout << endl;
    }
    
    return 0; // main 함수의 반환값 추가

}
