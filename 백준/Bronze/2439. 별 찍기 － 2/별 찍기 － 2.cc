#include <iostream>
using namespace std;


int main(int argc, char** argv) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n-i; j++)
			cout << " " ;
		for(int k = 0; k <= i; k++)
			cout << '*';
		cout << '\n';
	}

	return 0;
}