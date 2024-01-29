#include<iostream>
#include<algorithm>
#include <ctime>
#include <cstring>
#define MAX 1000001
#define INF 9999999
using namespace std;
int arr[MAX];
int psm[MAX];
int sum = 0;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int m;
    int n, st, en;
    cin >> n;
    cin >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        psm[i] = psm[i-1] + arr[i];
    }
        
    for(int i = 0; i < m; i++ ){
        cin >> st >> en;
        cout << psm[en] - psm[st-1] << '\n';
    }
    return 0;
}

