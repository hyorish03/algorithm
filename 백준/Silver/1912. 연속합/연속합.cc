#include<iostream>
#include <algorithm>
#define MAX 100005
using namespace std;

pair<int, int> d[MAX];
int arr[MAX];
// 수의 합을 구함
// 합의 최댓값을 도출

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    // first는 현재 합, second는 최댓값
    d[0] = {arr[0], arr[0]};
    
    for(int i = 1; i < n; i++){
        
        d[i].first = max(d[i-1].first + arr[i], arr[i]);
        d[i].second = max(d[i-1].second, d[i].first);
        
    }
    
    cout << d[n-1].second;
    return 0;
}