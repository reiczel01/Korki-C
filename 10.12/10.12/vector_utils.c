#include <stdio.h>
#include "vector_utils.h"
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
void display_vector(const int* tab, int size) {
    int i = 0;
    if (tab != NULL) {
        for (; i < size; i++) {
            printf("%d ", *(tab + i));
        }
    }

}
int create_histogram(const float* vec, int size, int* out, int out_size) {
    if (vec == NULL || out == NULL || size <= 0 || out_size <= 0) {
        return 1;
    }
    for (int i = 0; i < out_size; i++) {
        *(out + i) = 0;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < out_size; j++) {
            if (*(vec + i) >= j && *(vec + i) < j + 1) { //sprytne liczenie przediałów 
                *(out + j) += 1;
            }
        }
    }
        /*if (*(vec+i) >= 0 && *(vec + i) < 1) {
            *(out + 0) += 1;
        }
        else if (*(vec + i) >= 1 && *(vec + i) < 2) {
            *(out + 1) += 1;
        }
        else if (*(vec + i) >= 2 && *(vec + i) < 3) {
            *(out + 2) += 1;
        }
        else if (*(vec + i) >= 3 && *(vec + i) < 4) {
            *(out + 3) += 1;
        }
        else if (*(vec + i) >= 4 && *(vec + i) < 5) {
            *(out + 4) += 1;
        }
        else if (*(vec + i) >= 5 && *(vec + i) < 6) {
            *(out + 5) += 1;
        }
        else if (*(vec + i) >= 6 && *(vec + i) < 7) {
            *(out + 6) += 1;
        }
        else if (*(vec + i) >= 7 && *(vec + i) < 8) {
            *(out + 7) += 1;
        }
        else if (*(vec + i) >= 8 && *(vec + i) < 9) {
            *(out + 8) += 1;
        }
        else if (*(vec + i) >= 9 && *(vec + i) < 10) {
            *(out + 9) += 1;
        }
        else if (*(vec + i) >= 10 && *(vec + i) < 11) {
            *(out + 10) += 1;
        }*/

    
    return 0;
}