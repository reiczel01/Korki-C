#include <stdio.h>
#include "vector_utils.h"


int read_vector(int* tab, int size, int stop_value) {
    int i = 0;
    if (size <= 0 || tab == NULL || size > 150) {
        return -1;
    }
    for (; i < size; i++) { // temp - zm tymczasowa do sprawdzenia czy warto�� nie jest znakiem
        int temp = 0;

        if (scanf("%d", &temp) != 1) {
            return -2;
        }
        if (temp == stop_value) {
            return i; // zwruci zliczon� warto�� wykonania p�tli ( ilo�� element�w)
        }
        *(tab + i) = temp;// je�eli temp jest nok to nie wpisze do tablicy
    }

    return i; //liczba element�w poprawnie wczytanych
}
void display_vector(const int* tab, int size) {
    int i = 0;
    if (tab != NULL) {
        for (; i < size; i++) {
            printf("%d ", *(tab + i));
        }
    }

}
int shift(int* array, int array_size, int positions_to_shift, enum direction dir) {
    if (array_size <= 0 || array == NULL || positions_to_shift < 0 || dir < 1 || dir > 2) {
        return 1;
     }
    if (positions_to_shift == 0) {
        return 0; // gdy nic nie przesuwamy
    }
    int temp1[150];
    int* tempptr = &temp1[0]; // rzutowanie na wskażnik
    

    for (int i = 0; i < 150; i++) // zerowanie tablicy temp jeden zapisującej wyrazy przesuwane
    {
        *(tempptr + i) = 0;
    }
    
    if(positions_to_shift>array_size){
        while (positions_to_shift > array_size) {
            positions_to_shift = positions_to_shift - array_size;
        }
    }
    switch (dir)
    {
        case ROTATE_LEFT:
        {
            
            for (int i = 0; i < positions_to_shift; i++)
            {
                *(tempptr + i) = *(array + i);// przesuwanie znaków kture muszę dopisac do końca
            }
            for (int i = positions_to_shift; i < array_size; i++) { // przesuwamy całość o pozition to shift w lewo
                *(array + i - positions_to_shift) = *(array + i);
            }
            int j = 0; //licznik ile razy wykonuje sie pentla
            for (int i = array_size - positions_to_shift; i < array_size; i++) { // nadpisujemy na koniec naszego przesunięcia zawinięte elementy z temp1
                *(array + i) = *(tempptr + j);
                j++;
            }
            }

        break;
    
        case ROTATE_RIGHT:
        {
            int j = 0; //licznik ile razy wykonuje sie pentla
                for (int i = array_size - positions_to_shift; i < array_size; i++)//od pierwszego elementu do końca wpisuje sobie elementy do tempa
                {
                    *(tempptr + j) = *(array + i);// przesuwanie znaków kture muszę dopisac do końca
                    j++;
                }
                for (int i = array_size - positions_to_shift - 1; i >= 0; i--) { // przesuwamy całość o pozition to shift w prawo analogicznie do wcześniejszego switcha
                    *(array + i + positions_to_shift ) = *(array + i);
                }
                for (int i = 0; i < positions_to_shift; i++) { // nadpisujemy na początek naszego przesunięcia zawinięte elementy z temp1
                    *(array + i) = *(tempptr + i);
                }
                
        }
        break;
        default:
        {
        printf("Value not known");
        }
    }
    return 0;
}
