#include <iostream>
#include <utility>
using namespace std;

int d(int a) {
	
	int sum = a;

	while (a != 0) {
		sum = sum + a % 10;
		a /= 10;
	}

	return sum;
}

int main() {
	bool check[10001] = { false, };
	for (int i = 0; i < 10001; i++) {
		int n = d(i);
		if (n < 10001)
			check[n] = true;
	}

	for (int i = 0; i < 10001; i++)
		if(!check[i])
		cout << i << '\n';

}