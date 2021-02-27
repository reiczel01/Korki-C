

#include <stdio.h>
#include "vector_utils.h"
#include "sort.h"
void
clear(void)
{
    while (getchar() != '\n');
}

int main()
{
    int tab[50];
    int size = 0;
    int dir = 0;
    printf("Podaj wektor: \n");
    size = read_vector(tab, 50, 0);
    clear();
       if (size == 0) {
           printf("not enough data available");
           return 3;
       }else if(size == -2) {
           printf("incorrect input");
           return 1;
       }
       printf("Podaj kierunek sortowania: ");
       if (scanf("%d", &dir) != 1) {
           printf("incorrect input");
           return 1;
       }
       if (dir < 1 || dir>2) {
           printf("Incorrect input data");
           return 2;
       }
       selection_sort(tab, size, dir);
       display_vector(tab, size);
	return 0;
}
