#include <stdio.h>
#include "vector_utils.h"
int read_vector(int* tab, int size, int stop_value) {
    int i = 0;
    if (size <= 0 || tab == NULL || size > 50) {
        return -1;
    }
    for (; i < size; i++) { // temp - zm tymczasowa do sprawdzenia czy warto?? nie jest znakiem
        float temp = 0;

        if (scanf("%f", &temp) != 1) {
            return -2;
        }
        if (temp == stop_value) {
            return i; // zwruci zliczon? warto?? wykonania p?tli ( ilo?? element?w)
        }
        *(tab + i) = temp;// je?eli temp jest nok to nie wpisze do tablicy
    }

    return i; //liczba element?w poprawnie wczytanych
}
void display_vector(const int* tab, int size) {
    int i = 0;
    if (tab != NULL) {
        for (; i < size; i++) {
            printf("%d ", *(tab + i));
        }
    }

}

