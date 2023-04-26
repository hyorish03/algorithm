#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	unsigned long long a, b, temp, mx, mn;
	vector<unsigned long long> vec;
	
	cin >> a >> b;
	if (a > b) {
		temp = b;
		b = a;
		a = temp;
	}
	
	if (a == b)
		cout << 0 << endl;
	else {
		cout << b - a - 1 << endl;
		for (unsigned long long i = a + 1; i < b; i++)
			if ((b - a - 1) == 2)
				cout << i << endl;
			else cout << i << ' ' ;
	}
	
	
}

