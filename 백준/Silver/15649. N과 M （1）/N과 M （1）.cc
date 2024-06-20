#include <iostream>
#include <string.h>
#include <cstring>
#include <queue>
#include <vector>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAX 1001

using namespace std;
vector<int> ans;
vector<int> v;
bool visited[MAX];
int n, m;
int arr[9] = {0,};

void dfs(int cnt){
  if(cnt == m)
  {
      for(int i = 0; i < m; i++)
         cout << arr[i] << ' ';
      cout << '\n';
      return;
  }
    
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            visited[i] = true;
            arr[cnt] = i;
            dfs(cnt+1);
            visited[i] = false;
        }
    }
}

int main() {
    FASTIO;

    cin >> n >> m;
  
    dfs(0);
    
    return 0;
}


