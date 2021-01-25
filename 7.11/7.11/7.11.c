#include <stdio.h>
#include <math.h>
int is_prime(int a) {
	if (a < 2) {
		return 0;
	}
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			return 0;
		}
	}
	return 1;
}
int my_abs(int a) {
	if (a < 0) {
		return a * -1;
	}
	else {
		return a;
	}
}
int main() {
	
	int x = 0, y = 0, i = 0, mn = 0, mx =0;
	printf("Podaj x1 = ");
	if (scanf("%d", &x) != 1) {
		printf("Incorrect input");
		return 1;
	}
	printf("Podaj x2 = ");
	if (scanf("%d", &y) != 1) {
		printf("Incorrect input");
		return 1;
	}
	if (x > y) {
		mn = x;
		mx = y;
	}
	else {
		mn = y;
		mx = x;
	}
	//int count = 0;
	if (x == y) {
		printf("Nothing to show");
		return 2;
	}
	for (i = my_abs(mn - mx); i < mn; i++){
		is_prime(i);
		int redValue = is_prime(i);
		if (redValue == 1) {
			printf("%d ", i);
			//count = 1 + count;
		}
		/*if (count == 0 && i != my_abs(x - y)) {
			printf("Nothing to show");
			return 2;
		}*/
	}
	
}
