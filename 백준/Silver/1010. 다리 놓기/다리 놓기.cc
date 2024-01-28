#include<iostream>
#include<algorithm>
#include <ctime>
#include <cstring>
#define MAX 1000001
#define INF 9999999
using namespace std;

long long combi(int n, int m){

     long long modd = 1;
     long long div = 1;
    
    
    // 5C3이면 n은 3, m은 5
    // 5 * 4 / 2 * 1

    for(int i = m; i > m-n; i--){
        modd *= i;
        modd /= div;
        div++;
    }
   
    
    return modd;
}

int main()
{
    int tc;
    int n, m;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
         cout << combi(n, m) << '\n';
        
    }
    return 0;
}

