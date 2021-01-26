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
//int my_abs(int a) {
//	if (a < 0) {
//		return a * -1;
//	}
//	else {
//		return a;
//	}
//}

int main()
{
	int x;
	int y;
	int inValue = 0;
	int count = 0;
	printf("Podaj x1 = ");
	inValue += scanf("%d", &x);
	if (inValue != 1){
		printf("Incorrect input");
		return 1;
	}
	printf("Podaj x2 = ");
	inValue += scanf("%d", &y);

	if (inValue != 2 || y < x){
		printf("Incorrect input");
		return 1;
	}

	for (int i = x; i <= y; i++){
		if (is_prime(i)){
			printf("%d ", i);
			count++;
		}
	}

	if (count == 0) {
		printf("Nothing to show");
	}
}
