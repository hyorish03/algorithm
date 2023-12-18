#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;

    vector<long long> snacks(N);
    for (int i = 0; i < N; i++)
    {
        cin >> snacks[i];
    }

    sort(snacks.begin(), snacks.end(), greater<long long>());

    long long left = 1, right = snacks[0], result = 0;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long totalSnacks = 0;

        for (int i = 0; i < N; i++)
        {
            totalSnacks += snacks[i] / mid;
        }

        if (totalSnacks >= M)
        {
            result = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}
