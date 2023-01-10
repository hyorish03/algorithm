#include <stdio.h>
int main(){
	long long n1, n2;
		
	scanf("%lld %lld", &n1, &n2);

	if (n1 > n2)
		printf(">");
	else if (n1 == n2)
		printf("==");
	else
		printf("<");

	return 0;
}