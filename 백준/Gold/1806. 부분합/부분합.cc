#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100000000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n >> s;

    vector<int> sequence(n);

    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    int start = 0, end = 0;
    int sum = 0, minLength = MAX;

    while (end < n) {
        sum += sequence[end++];
        
        while (sum >= s) {
            minLength = min(minLength, end - start);
            sum -= sequence[start++];
        }
    }

    if (minLength == MAX) {
        cout << "0\n";
    } else {
        cout << minLength << "\n";
    }

    return 0;
}
