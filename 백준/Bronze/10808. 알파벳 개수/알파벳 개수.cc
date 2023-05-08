#include<iostream>
#include<string>
using namespace std;
int arr[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
		arr[s[i] - 97]++;

	for (int i = 0; i < 26; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}
