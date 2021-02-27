#include <stdio.h>
#include "vector_utils.h"
int main() {
    int tab[100];
    int min = 0;
    printf("podaj dwie liczby\n");
    int numOfElements =  read_vector(tab, 100, -1);
    if (numOfElements == -2) {
        printf("Incorrect input");
        return 1;
    }
    if (numOfElements == 0) {
        printf("Not enough data available");
        return 3;
    }
    find_min(tab, numOfElements, &min);
    printf("Min: %d", min);
    
    return 0;
}