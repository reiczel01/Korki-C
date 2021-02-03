

#include <stdio.h>
#include <stdlib.h>



int main()
{
	float T[100];
	float* wskaznik = &T[0]; //zmienna wskaźnikowa wskazująca na zerowy element tablicy T
	int j = 0;
	for (int i = 0; i < 100; i++) {

		*(wskaznik + i) = 0.0; //zerujemy tablicę 
	}
	printf("Ile liczb chcesz wprowadzić?:");
	if (scanf("%d", &j) != 1) {
		printf("Incorrect input");
		return 1;
	}
	if (j > 100 || j<=0) {
		printf("Incorrect input data");
		return 2;
	}
	printf("Podaj liczby:");

	for (int i = 0; i < j; i++) { // temp - zm tymczasowa do sprawdzenia czy wartość nie jest znakiem
		float temp = 0;
		if (scanf("%f", &temp) != 1) {
			printf("Incorrect input");
			return 1;
		}
		*(wskaznik + i) = temp;// jeżeli temp jest nok to nie wpisze do tablicy
	}
	
	float suma = 0.0;
	for (int i = j - 1; i >= 0; i--) { //pentla sumująca od tyłu z poprawką żeby nie brało komurki z poza zakresu
		printf("%f ", *(wskaznik + i));
		suma += *(wskaznik + i); //sumowanie kolejnych wyrazów
	}
	
	printf("\nSuma: %.2f\n", suma);
	printf("Srednia: %.2f", (suma / j));
	return 0;
}
