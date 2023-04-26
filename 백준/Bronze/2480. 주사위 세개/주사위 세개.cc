#include <iostream>

using namespace std;

int main() {
	int a, b, c, temp;

	cin >> a >> b >> c;

	if (a == b && b == c)
		cout << 10000 + a * 1000;
	else if ((a == b || a == c) && b != c)
		cout << 1000 + a * 100;

	else if (b == c && a != b)
		cout << 1000 + b * 100;
	else {
		if (a > b)
			temp = a;
		else
			temp = b;

		if (temp < c)
			temp = c;

		cout << temp * 100;
	}
	
}