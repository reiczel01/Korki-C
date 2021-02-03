

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	srand(time(NULL)); //zerowanie licznika czasu na któym bazuje funkcaj rand
	int T[20];
	int* wskaznik = &T[0]; //zmienna wskaźnikowa wskazująca na zerowy element tablicy T
	for (int i = 0; i < 20; i++) {

		*(wskaznik + i) = rand()%20; //przypisuje randomowe wartości do tablicy T 
	}
	for (int i = 0; i < 20; i++) {

		printf("%d ", *(wskaznik + i));
	}
	printf("\n");
	for (int i = 0; i < 20; i+=2) {

		printf("%d ", *(wskaznik + i));
	}
	return 0;
}
