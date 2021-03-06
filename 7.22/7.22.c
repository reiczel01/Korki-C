﻿



#include <stdio.h>


int concat_begin(const int first[], int size, const int second[], int size2, int dest[], int size3)
{

    if (size<1||size2<1|| size3<1) {
        return -1;
    }
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
  
    if (size < 1 || size2 < 1 || size3 < 1) {
        return -1;
    }
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
    int k = n;
    for (int i = numOfIteration; i < (size + size2); i++) {
        if (mlg == 1) {
            dest[i] = second[k];
        }
        else {
            dest[i] = first[k];
        }
        num++;
        k++;
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
    if (size<1) {
        return -1;
    }
   
    while(1){
        int temp = 0;
        if (scanf("%d", &temp) != 1){
            printf("incorrect input\n");
        return -2;
        }
        if (i == 0 && temp == stop_value) {
            printf("not enough data available");
            return -3;
        }
        if (temp == stop_value)
        {
            return i;
        }
        if (i == size) {
            continue;
        }
        vec[i] = temp;
        i++;
    }
    return i;
}

int main() {
    int first[50];
    int second[50];
    int dest[100];
    printf("podaj pierwszy wektor: ");
    int inValue = read_vector(first, 50, 0);
    if (inValue == -2 ) {
        return 1;
    }else if (inValue == -3) {
        return 2;
    }
    printf("podaj drugi wektor: ");
    int in2Value = read_vector(second, 50, 0);
    if (in2Value == -2) {
        return 1;
    }else if(in2Value == -3) {
        return 2;
    }
    display_vector(first, inValue);
    printf("\n");
    display_vector(second, in2Value);
    printf("\n");
    
    if (inValue + in2Value > 50) {
        printf("Output buffer is too small\n");
        return 0;
    }
   int retValue = concat_begin(first,inValue, second,in2Value ,dest, in2Value+inValue );
   if (retValue != -2) {
       display_vector(dest, retValue);
       printf("\n");
   }
  
   
   retValue = concat_end(first, inValue, second, in2Value, dest, in2Value + inValue);
   if (retValue != -2) {
       display_vector(dest, retValue);
       printf("\n");
   }
  

   
    retValue = concat_zip(first, inValue, second, in2Value, dest, in2Value + inValue);
    if (retValue != -2) {
        display_vector(dest, retValue);
        printf("\n");
    }
   

    return 0;
}
