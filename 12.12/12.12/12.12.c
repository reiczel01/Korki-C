#include <stdio.h>
#include <stdlib.h>
int isBinaryEven(unsigned int n)
{

	
	//int binaryNum[32];
	int* iLoveDante = (int*)malloc(32 * sizeof(int));
	for (int i = 0; i < 32; i++) {
		*(iLoveDante + i) = 0;
	}
	
	int i = 0;
	while (n > 0) {

		
		*(iLoveDante + i) = n % 2;
		n = n / 2;
		i++;
	}
	
	int countBIN = 0;
	for (i = 0; i < 32; i++) {
		if (*(iLoveDante + i) == 1)
			countBIN++;
	}
	if (countBIN % 2 == 1) {
		return 0;
	}
	else {
		return 1;
	}
	free(iLoveDante);
}
int main()
{
	unsigned int n;
	printf("Podaj wartosc: ");
	if (scanf("%u", &n) != 1) {
		printf("Incorrect input");
		return 1;
	}
	if (isBinaryEven(n) == 1) {
		printf("YES");
	}
	else {
		printf("NO");
	}
	
	return 0;
}
