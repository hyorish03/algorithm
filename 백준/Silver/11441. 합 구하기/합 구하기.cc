#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100000
#define INF 987654321
using namespace std;

int psum[MAX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;
    int arr[num];
    
    for(int i = 1; i <= num; i++){
        cin >> arr[i];
    }
    
    psum[0] = 0;
    
    for(int i = 1; i <= num; i++){
        psum[i] = psum[i-1] + arr[i];
    }
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        
        cout << psum[b]-psum[a-1] << '\n';
    }
    
    return 0;
}
