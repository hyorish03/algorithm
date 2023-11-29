#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10

using namespace std;

int n, m, k;
int arr[MAX];
int inp[MAX];
bool vis[MAX];
void dfs(int cur,int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << endl;
        return;
    }
    
    for(int i = 0; i < n; i++){
        if(inp[i] >= cur){
           
            arr[cnt]=inp[i];
            dfs(inp[i], cnt+1);
           
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        inp[i] = k;
    }
    sort(inp, inp+n);
    dfs(0, 0);
    
}
