#include <iostream>

using namespace std;
#define MAX 101

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, X;
    int a;
    
    cin >> N >> X;
    
    for(int i = 0; i < N; i++){
        cin >> a;
        
        if(X>a)
            cout << a << ' ';
    }
    
}
