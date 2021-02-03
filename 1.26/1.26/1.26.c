
#include <stdio.h>

int main()
{
	int day, month, year;
	printf("Podaj datę:");
	scanf("%02d-%02d-%04d", &day, &month, &year);
	printf("Day:%02d\nMontch:\t%02d\nYear:\t%04d", day, month, year);
	return 0;
}
