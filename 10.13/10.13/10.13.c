

#include <stdio.h>

int swap(int *a, int *b) {
	if (a == NULL || b == NULL) {
		return 1;
	}
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
	
	return 0;
}

int main()
{
	int a;
	int b;
	printf("Wpisz 2 liczby int oddzielajac spacja\n");
	int spr = scanf("%d %d", &a, &b);
	if (spr != 2)
	{
		printf("Incorrect input");
		return 1;
	}
	swap(&a, &b);
	printf("a: %d, b: %d", a, b);
	return 0;
}
