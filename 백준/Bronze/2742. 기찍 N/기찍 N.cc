#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = n; i > 0; i--)
		cout << i << "\n";
}