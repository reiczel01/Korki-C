#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"

void
clear(void)
{
    while (getchar() != '\n');
}
int main()
{
    //int tablica;
    int* tab = (int*)malloc(150 * sizeof(int));
  
    printf("Wpisuj wartosci calkowite: ");
    int size = read_vector(tab, 150, 0);// zwróci mi ile ma elementów  + sprawdzi i wczyta
    clear();
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
    int przesuniencie = 0;
    printf("Podaj przesuniecie: ");
    int spr = scanf("%d", &przesuniencie);
    if (spr != 1) {
        printf("Incorrect input");
        free(tab);
        return 1;
    }

    printf("Podaj kierunek przesuniecia: ");
    int dir = 0;
    spr = scanf("%d", &dir);
    if (spr != 1) {
        printf("Incorrect input");
        free(tab);
        return 1;
    }
    if (dir < 1 || dir > 2) {
        printf(" Incorrect input data");
        free(tab);
        return 2;
    }
    /*display_vector(tab, size);
    printf("\n");*/
    shift(tab, size, przesuniencie , dir);
    display_vector(tab, size);
    free(tab);
    return 0;
}
