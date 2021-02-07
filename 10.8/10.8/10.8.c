#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"


int main()
{
	
	//int tablica;
	int* tab = (int*)malloc(100 * sizeof(int));
	for (int i = 0; i < 100; i++)
	{
		*(tab + i) = 0; // wskaźnik na zerowy element + i (iteracja pentli)
	}
	printf("Wpisuj wartosci calkowite\n");
	int size = read_vector(tab, 100, -1);// zwróci mi ile ma elementów  + sprawdzi i wczyta
	if (size == 0) {
		printf("Not enough data available");
		free(tab);
		return 3;
	}
	if (size < 0) {
		printf("Incorrect input");
		free(tab);
		return 1;
	}
	sort(tab, size);
	display_vector(tab, size);
	free(tab);
	return 0;
}
