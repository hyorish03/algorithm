#include <iostream>
using namespace std;

int N;
int numbers[11]; // 수열 
int calc[4]; // 연산자의 개수
int mmin = 1000000001;
int mmax = -1000000001;
void dfs(int result, int idx)
{
    if(idx == N)
    {
        if(result > mmax)
            mmax = result;
        if(result < mmin)
            mmin = result;
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        if(calc[i] > 0)
        {
            calc[i]--;
            if(i == 0)
                dfs(result + numbers[idx], idx+1);
            else if(i == 1)
                dfs(result - numbers[idx], idx+1);
            else if(i == 2)
                dfs(result * numbers[idx], idx+1);
            else
                dfs(result / numbers[idx], idx+1);
            calc[i]++;
        }
    }
    return;
}
int main() {
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> numbers[i];
    for(int i = 0; i < 4; i++)
        cin >> calc[i];
    dfs(numbers[0],1);
    cout << mmax << '\n';
    cout << mmin;
}