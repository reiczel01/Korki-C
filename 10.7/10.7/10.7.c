

#include <stdio.h>
#include <stdlib.h>

int sum(const float* tab, unsigned int size, float* result) {
	if(size == 0 || result == NULL || tab == NULL) {
		return 1;
	}
	float suma = 0.0;
	for (int i = size - 1; i >= 0; i--) { //pentla sumująca od tyłu z poprawką żeby nie brało komurki z poza zakresu
		suma += *(tab + i); //sumowanie kolejnych wyrazów
	}
	*result = suma; //zapisanie wartości suma w miejsce pamięci wskazywane przez zmienną wskaźnikowa result
	return 0;
}
int avg(const float* tab, unsigned int size, float* result) {
	int retVal = sum(tab, size, result);
	if (retVal == 1) {
		return 1;
	}
	*result = *result / size;
	return 0;
}
int read_vector_float(float* vec, int size, float stop_value) {
	int i = 0;
	if (size <= 0 || vec == NULL) {
		return -1;
	}
	for (; i < size; i++) { // temp - zm tymczasowa do sprawdzenia czy wartość nie jest znakiem
		float temp = 0;
		
		if (scanf("%f", &temp) != 1) {
			return -2;
		}
		if (temp == stop_value) {
			return i; // zwruci zliczoną wartość wykonania pętli ( ilość elementów)
		}
		*(vec + i) = temp;// jeżeli temp jest nok to nie wpisze do tablicy
	}

	return i; //liczba elementów poprawnie wczytanych
}

int main()
{
	float T[100];
	float* wskaznik = &T[0]; //zmienna wskaźnikowa wskazująca na zerowy element tablicy T
	int j = 0;
	float suma, avg_zm;
	for (int i = 0; i < 100; i++) {

		*(wskaznik + i) = 0.0; //zerujemy tablicę 
	}
	
	printf("Podaj liczby:");
	
	j = read_vector_float(wskaznik, 100, 0);
	if (j == -2) {
		printf("Incorrect input");
		return 1;
	}
	if (j == 0) {
		printf("Not enough data available");
		return 3;
	}

	sum(wskaznik, j, &suma); //adres zmiennej suma przekazujemy by muc zmodyfikowac wartość wewnątsz funkcji
	avg(wskaznik, j, &avg_zm);
	printf("Suma: %.2f\n", suma);
	printf("Srednia: %.2f\n", avg_zm);
	return 0;
}
