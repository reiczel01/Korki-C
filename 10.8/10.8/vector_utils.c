#include <stdio.h>
#include "vector_utils.h"
int read_vector(int* tab, int size, float stop_value) {
	int i = 0;
	if (size <= 0 || tab == NULL) {
		return -1;
	}
	for (; i < size; i++) { // temp - zm tymczasowa do sprawdzenia czy wartoœæ nie jest znakiem
		float temp = 0;

		if (scanf("%f", &temp) != 1) {
			return -2;
		}
		if (temp == stop_value) {
			return i; // zwruci zliczon¹ wartoœæ wykonania pêtli ( iloœæ elementów)
		}
		*(tab + i) = temp;// je¿eli temp jest nok to nie wpisze do tablicy
	}

	return i; //liczba elementów poprawnie wczytanych
}