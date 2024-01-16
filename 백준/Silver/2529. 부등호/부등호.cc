#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int k;
char c[10];
bool check[10];
vector<string> ans;

bool check_can(string num) {
    for (int i = 0; i < k; i++) {
        if (c[i] == '>') {
            if (num[i] < num[i + 1]) return false;
        }
        else if (c[i] == '<') {
            if (num[i] > num[i + 1]) return false;
        }
         
    }
    return true;
}
void dfs(int index, string num) {
    if (index == k + 1) {
        if (check_can(num)) ans.push_back(num);
        return;
    }
    for (int i = 0; i <= 9; i++) {
        if (check[i]) continue;
        check[i] = true;
        dfs(index + 1, num+to_string(i));
        check[i] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> k;
    for (int i = 0; i < k; i++) cin >> c[i];
    dfs(0, "");
    auto mmin = *min_element(ans.begin(), ans.end());
    auto mmax = *max_element(ans.begin(),ans.end());
    
    cout << mmax << '\n'<< mmin;
}
