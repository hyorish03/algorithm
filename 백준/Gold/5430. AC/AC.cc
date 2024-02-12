#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAX 10000001
using namespace std;

int main() {
    FASTIO;
    int TC, n;
    string AC, nums;
    cin >> TC;
    while(TC--){
        cin >> AC;
        cin >> n;
        cin >> nums;
        
        vector<int> arr;
        int num;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= '0' && nums[i] <= '9'){
                num = 0;
                while(i < nums.size() && nums[i] >= '0' && nums[i] <= '9'){
                    num = num * 10 + (nums[i] - '0');
                    i++;
                }
                arr.push_back(num);
            }
        }
        
        bool reverse_flag = false;
        int start = 0, end = arr.size();
        bool error = false;
        for(char op : AC){
            if(op == 'R'){
                reverse_flag = !reverse_flag;
            } else if(op == 'D'){
                if(start == end){
                    cout << "error" << '\n';
                    error = true;
                    break;
                }
                if(reverse_flag){
                    end--;
                } else {
                    start++;
                }
            }
        }
        
        if(!error){
            cout << '[';
            if(start <= end){
                if(reverse_flag){
                    for(int i = end - 1; i >= start; i--){
                        cout << arr[i];
                        if(i != start) cout << ',';
                    }
                } else {
                    for(int i = start; i < end; i++){
                        cout << arr[i];
                        if(i != end - 1) cout << ',';
                    }
                }
            }
            cout << ']' << '\n';
        }
    }
    
    return 0;
}
