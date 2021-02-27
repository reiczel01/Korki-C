#include <stdio.h>
#include "sort.h"
#include "vector_utils.h"

int selection_sort_asc(int tab[], int size) 
{
    if (tab == NULL || size <= 0) {
        return 1;
    }
    int min; 
            
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++) 
            if (tab[j] < tab[min])
                min = j;

        
        int temp = *(tab + i); 
        *(tab + i) = *(tab + min); 
        *(tab + min) = temp;
        display_vector(tab, size);
        printf("\n");
    }
    return 0;
}

int selection_sort_desc(int tab[], int size) {
    if (tab == NULL || size <= 0) {
        return 1;
    }
    int min;  

    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
            if (tab[j] > tab[min])
                min = j;


        int temp = *(tab + i); 
        *(tab + i) = *(tab + min); 
        *(tab + min) = temp;
        display_vector(tab, size);
        printf("\n");
    }
    return 0;
}

int selection_sort(int tab[], int size, enum direction dir) {
    if (dir == ASCENDING) {
        return selection_sort_asc(tab, size);
    }
    else if (dir == DESCENDING) {
       return selection_sort_desc(tab, size);
    }
    else {
        
        return 1;
    }
    
}