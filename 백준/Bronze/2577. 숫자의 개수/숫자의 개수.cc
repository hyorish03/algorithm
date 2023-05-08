#include <iostream>
#include <string>

using namespace std;
int arr[10];
int main() {
	int a, b, c, mul;
	string str;

	cin >> a >> b >> c;
	mul = a * b * c;

	str = to_string(mul);

	for (int i = 0; i < str.size(); i++) {
		arr[str[i]-48]++;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}