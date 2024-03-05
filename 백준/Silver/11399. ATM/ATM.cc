#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> a(n);
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
   
    sort(a.begin(), a.end());
   
    int sum = 0, temp = 0;
    for(int i = 0; i < n; i++){
        temp = 0;
        for(int j = 0; j <= i; j++){
            temp += a[j];
        }
        sum += temp;
    }
    cout << sum;
    return 0;
}
