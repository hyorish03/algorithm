#include<iostream>
using namespace std;

int k, n, ans;
int line[10001];
int  maxi = 0;
long long mid, last, first;

int main()
{
    cin >> k >> n;
    
    for (int i = 0; i < k; i++)
    {
        cin >> line[i];
        if (maxi < line[i]) maxi = line[i];
    }
    first = 1;
    last = maxi;
    ans = 0;

    while (first <= last)
    {
        mid = (first + last) / 2;
        int cnt = 0;
        for (int i = 0; i < k; i++)
            cnt += line[i] / mid;

        if (cnt >= n) {
            first = mid + 1;
            if (ans < mid) ans = mid;
        }
        else {
            last = mid - 1;
        }
    }
    
    cout << ans;
}
