#include<iostream>
#include<algorithm>
#define MAX_SIZE 1003
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	vector<long long> v;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		v.push_back(x);
	}
	
	int left = 0, right = v.size() - 1;
	int minV = abs(v[right] + v[left]);
	int answer = v[right] + v[left];
	while (left < right) {
		int val = v[left] + v[right];
		if (abs(val) < minV) {
			minV = abs(val);
			answer = val;
		}

		if (val < 0) {
			left++;
		}
		else right--;
	}
	cout << answer << endl;

	return 0;
}