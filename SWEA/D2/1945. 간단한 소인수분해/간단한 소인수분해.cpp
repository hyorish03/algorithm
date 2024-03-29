#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX 1001
using namespace std;

int main () {
    int t;
    cin >> t;
    int idx = 0;
    while(t--){
        int num;
        idx++;
        cin >> num;
        int a=0, b=0, c=0, d=0, e=0;
        while(num % 2 == 0){
            num /= 2;
            a++;
        }
        while(num % 3 == 0){
            num /= 3;
            b++;
        }
        while(num % 5 == 0){
            num /= 5;
            c++;
        }
        while(num % 7 == 0){
            num /= 7;
            d++;
        }
        while(num % 11 == 0){
            num /= 11;
            e++;
        }
        cout << "#" << idx << ' ' << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << endl;
    }
    return 0;
}
