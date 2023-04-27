#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int a, b;
	int sumM = 0, sumY = 0;

	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> b;
		if (b >= 60) {
			sumM += ((b / 30 + 1) * 10);
			sumY += ((b / 60 + 1) * 15);
		}
		else if (b < 30) {
			sumM += 10;
			sumY += 15;
		}
		else if (b >= 30 && b < 60) {
			sumM += ((b / 30 + 1) * 10);
			sumY += 15;

		}
	}

	if (sumM == sumY)
		cout << 'Y' << ' ' << 'M' << ' ' << sumM;
	if (sumM > sumY)
		cout << 'M' << ' ' << sumY;
	if (sumM < sumY)
		cout << 'Y' << ' ' << sumM;

}