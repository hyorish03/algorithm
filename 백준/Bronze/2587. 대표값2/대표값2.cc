#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> arr;
	int sum = 0;
	int n;
	for(int i = 0; i < 5; i++){
		cin >> n;
		sum += n;
		arr.push_back(n);
	}

	sort(arr.begin(), arr.end());

	cout << sum / 5 << '\n' << arr[2];
}

