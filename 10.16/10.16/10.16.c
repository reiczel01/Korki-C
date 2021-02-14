#include <stdio.h>
#include <stdlib.h>
int is_prime(int a) {
    if (a < 2) {
        return 0;
    }
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int tab[10][10];
    int (*tabWsk)[10] = &tab[0];
    int i = 0, j = 0;//i - całkowiat liczab elementów
   
    printf("podaj liczby:");
    while(i < 100) {
        int temp;
        if (scanf("%d", &temp) != 1) {
            printf("Incorrect input");
            return 1;
        }
        if (is_prime(temp) == 1) {
            //printf(“ % d “, *(*(p + i) + j));
            *(*(tabWsk + j) + i) = temp;
           
            i++;
        }
        
    }
   
    for (int m = 0; m < 10; m++) {
        for (int n = 0; n < 10; n++) {
            if (m % 3 == 0 && n % 3 == 0) {
                printf("%d ", *(*(tabWsk + m) + n));
            }
        }
        
    }

	return 0;
}
