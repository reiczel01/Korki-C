

#include <stdio.h>
int add(int a, int b) {
	return (a + b);
}
int main()
{
	int a, b;
	printf("Podaj pierwszą liczbę: ");
	if (scanf("%d", &a) != 1) {
		printf("Incorrect input");
		return 1;
	}
	
	printf("Podaj drugą liczbę: ");
	if (scanf("%d", &b) != 1) {
		printf("Incorrect input");
		return 1;
	}
	
	printf("wynik: %d", add(a, b));
	return 0;
}
