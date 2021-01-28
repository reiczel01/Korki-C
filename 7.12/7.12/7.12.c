

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


int is_twin(int a, int b) {
	if (is_prime(a) == 1) {
		if (is_prime(b) == 1) {
			if (a - b == 2 || a - b == -2) {
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int inValue = 0;
	int a;
	int b;
	
	

	printf("Podaj x1 = ");
	inValue = scanf("%d", &a);
	if (inValue != 1) {
		printf("Incorrect input");
		return 1;
	}
	printf("Podaj x2 = ");
	inValue = scanf("%d", &b);

	if (inValue != 1 || b < a) {
		printf("Incorrect input");
		return 1;
	}
	int atLeastOne = 0;
	for (int i = a; i < b; i++) {
		for (int j = i + 1; j <= b ; j++) {
			if (is_twin(i, j)) {
				printf("%d, %d\n", i, j);
				atLeastOne = 1;
				//count++;
			}
		}
	}
	if (atLeastOne == 0) {
		printf("Nothing to show");
	}
	//inValue = is_twin(5,7);
	//printf("%d", inValue);
	return 0;
}

