#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 21

int main(int argc, char**argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> v(N);
	int start, end;
	
	for(int i=0; i<N; i++){
		v[i]=i;
	}
	
	for(int i=0; i<10; i++){
		cin >> start >> end;
		
		reverse(v.begin() + start, v.begin() + end + 1);
	}
	
	for(int i=1; i<N; i++){
		cout << v[i] <<" ";
	}
	
	
	return 0;
}