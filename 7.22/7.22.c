



#include <stdio.h>

int concat_begin(const int first[], int size, const int second[], int size2, int dest[], int size3)
{
    if (size + size2 > size3) {
        return -2;
    }
    int j = 0, n = 0;
    for (int i = 0; i < size3; i++) {
        if (j < size) {
            dest[i] = first[j];
                j++;
        }else if (n < size2)
        {
            dest[i] = second[n];
            n++;
        }
       
    }
 
    return j + n;
}
int concat_end(const int first[], int size, const int second[], int size2, int dest[], int size3) {
    return concat_begin(second, size2, first, size, dest, size3);
}
int concat_zip(const int first[], int size, const int second[], int size2, int dest[], int size3) {
    if (size + size2 > size3) {
        return -2;
    }
    int j = 0, n = 0;
    int mlg;
    int numOfIteration = 0;
    int num = 0;
    if (size < size2) {
        numOfIteration = size * 2;
        mlg = 1;
    }
    else {
        numOfIteration = size2 * 2;
        mlg = 0;
    }
    for (int i = 0; i < numOfIteration; i++) {
        if (i % 2 == 0) {
            dest[i] = first[j];
            j++;
        }
        else {
            dest[i] = second[n];
            n++;
        }
    }
    for (int i = numOfIteration; i < (size + size2); i++) {
        if (mlg == 1) {
            dest[i] = second[i];
        }
        else {
            dest[i] = first[i];
        }
        num++;
    }
    return j + n + num;
}
void display_vector(const int vec[], int size) {
    
    for (int i = 0; i < size; i++) {
        printf("%d ", vec[i]);
    }
}
int read_vector(int vec[], int size, int stop_value) {
    int i = 0;
    if (size == 0) {
        return -1;
    }
    while(1){
        int temp = 0;
        if (scanf("%d", &temp) != 1){
        return -2;
        }
        if (temp == stop_value)
        {
            return i;
        }
        if (i == size) {
            return i;
        }
        vec[i] = temp;
        i++;
    }
}

int main() {
    int first[50];
    int second[50];
    int dest[100];
    printf("podaj pierwszy wektor: ");
    int inValue = read_vector(first, 50, 0);
    printf("podaj drugi wektor: ");
    int in2Value = read_vector(second, 50, 0);

    display_vector(first, inValue);
    printf("\n");
    display_vector(second, in2Value);
    printf("\n");
   
   int retValue = concat_begin(first,inValue, second,in2Value ,dest, in2Value+inValue );
   display_vector(dest, retValue);
   retValue = concat_end(first, inValue, second, in2Value, dest, in2Value + inValue);
   printf("\n");
    display_vector(dest, retValue);
    printf("\n");
    retValue = concat_zip(first, inValue, second, in2Value, dest, in2Value + inValue);
    display_vector(dest, retValue);
    printf("\n");
   
   
}
