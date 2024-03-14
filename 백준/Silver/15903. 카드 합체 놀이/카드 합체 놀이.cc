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
    
    int cardNum, calc;
    cin >> cardNum >> calc;
    priority_queue<long long int, vector<long long int>, greater<long long int>>pq;
    for(int i = 0; i < cardNum; i++){
        int a;
        cin >> a;
        pq.push(a);
    }
    
    while(calc--){
        long long int x, y;
        x = pq.top();
        pq.pop();
        y = pq.top();
        pq.pop();
        
        for(int i = 0; i < 2; i++){
            pq.push(x+y);
        }
    }
    
    long long int sum = 0;
    
    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
    }
    
    cout << sum;
    return 0;
}
