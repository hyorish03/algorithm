#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Sub{
    int start;
    int end;
};

struct cmp{
    bool operator()(Sub a, Sub b){
        if(a.end == b.end){ // 종료시간이 같을 경우 시작시간이 작은것부터
            return a.start > b.start;
        }
        return a.end > b.end; // 종료시간이 빠른것부터
    }
};
priority_queue<Sub, vector<Sub>, cmp> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Sub sub;
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int st, en;
        cin >> st >> en;
        sub.start = st;
        sub.end = en;
        pq.push(sub);
    }
    
    int end = 0;
    int tot = 0;
    
    while(pq.size()>0){
        sub = pq.top();
        if(end <= sub.start){
            tot++;
            end = sub.end;
        }
        pq.pop();
    }
    
    cout << tot;
    return 0;
}
