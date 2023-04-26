#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector <int> vec;
	int arr[7];
	int sum = 0, odd = 0;


	for (int i = 0; i < 7; i++) {
		cin >> arr[i];
	
	}
	for (int i = 0; i < 7; i++) {
		if (arr[i] % 2 != 0) {
			sum += arr[i];
			vec.push_back(arr[i]);
			odd++;
		}
		
	}

	if (odd == 0)
		cout << -1;
	else {
		int min = *min_element(vec.begin(), vec.end());
		cout << sum << "\n" << min;
	}

	
}

