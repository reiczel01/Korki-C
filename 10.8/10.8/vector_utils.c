#include <stdio.h>
#include "vector_utils.h"
int read_vector(int* tab, int size, int stop_value) {
	int i = 0;
	if (size <= 0 || tab == NULL || size > 100) {
		return -1;
	}
	for (; i < size; i++) { // temp - zm tymczasowa do sprawdzenia czy warto�� nie jest znakiem
		float temp = 0;

		if (scanf("%f", &temp) != 1) {
			return -2;
		}
		if (temp == stop_value) {
			return i; // zwruci zliczon� warto�� wykonania p�tli ( ilo�� element�w)
		}
		*(tab + i) = temp;// je�eli temp jest nok to nie wpisze do tablicy
	}

	return i; //liczba element�w poprawnie wczytanych
}
void display_vector (const int* tab, int size) {
	int i = 0;
	if (tab != NULL) {
		for (; i < size; i++) {
			printf("%d ", *(tab + i));
		}
	}
	
}
int sort(int* tab, int size) {
	if (tab == NULL || size <= 0) {
		return 1;
	}
	int temp = 0; // zmienna zo zamiany miejsc w przypadku sortowania
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size - i; j++) { //p�tla do por�wnainia czy nie ma zmiennej wi�kszej od pierwszej
			if (*(tab + j -1) > *(tab+j)) {// czy poprzedni element wi�kszy od poprzedniego
				//zamiana miejscami
				temp = *(tab + j); // zapisjue sobie tab od j �eby nie straci� zmiennej
				*(tab + j) = *(tab + j - 1); // podmieniam zmienn�
				*(tab + j - 1) = temp;// powracam do warto�ci wcze�niejszej
			}
		}
	}
	return 0;
}