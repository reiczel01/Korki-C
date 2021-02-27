

#include <stdio.h>


int main()
{
	int T[10];
	int* wskaznik = &T[0]; //zmienna wskaźnikowa wskazująca na zerowy element tablicy T
	for (int i = 0; i < 10; i++) {
		
		*(wskaznik + i) = i; //przypisuje kolecne wartości do tablicy T 
	}
	for (int i = 0; i < 10; i++) {

		printf("%d ", *(wskaznik + i));
	}
	return 0;
}
