#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 9

int N,M;
int first[MAX];
int arr[MAX];
vector<int> ans;
bool vis[MAX];

void dfs(int cnt) { //현재 위치
    if(cnt == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << ' ';
        }cout << '\n';
        return;
    }
    
    int xx = 0;
    
    for(int i = 0; i < N; i++){
        if(!vis[i] && first[i] != xx ){
            if(arr[cnt-1] <= first[i]){
                vis[i] = true;
                arr[cnt] = first[i];
                xx = arr[cnt];
                dfs(cnt+1);
                vis[i] = false;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for(int i=0;i<N;i++)
        cin >> first[i];
    
    sort(first,first+N); //정렬

    dfs(0);
}
