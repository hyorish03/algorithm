#include <iostream>

using namespace std;

int main(){
	int i, j, temp;
	int nums[3];

	for (int i = 0; i < 3; i++)
		cin >> nums[i];

	for(int i = 0; i < 3; ++i)
		for(int j = i+1; j < 3; j++)
			if (nums[i] > nums[j]) {
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
	for (int i = 0; i < 3; i++)
		cout << nums[i] << endl;
}