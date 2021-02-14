

#include <stdio.h>
#include "vector_utils.h"

int main()
{
	int numOfElements = 0;
	float vec[100];
	int his[11];
	printf("Podaj liczby: ");
	numOfElements = read_vector_float(vec, 100, -1);
	if (numOfElements == 0) {
		printf("Not enough data available");
		return 3;
	}
	if (numOfElements == -2) {
		printf("Incorrect input");
		return 1;
	}
	create_histogram(vec, numOfElements, his, 11);
	display_vector(his, 11);

	
	return 0;
}
