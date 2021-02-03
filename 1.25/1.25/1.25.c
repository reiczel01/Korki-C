#include <stdio.h>

int main()
{
    int a, b, c, d;


    printf("Podaj numer telefonu: ");
    scanf("%03d-%02d-%02d", &b, &c, &d);
  
    printf("Podaj numer kierunkowy: ");
    scanf("%02d", &a);
   
        printf("(%02d) %03d-%02d-%02d", a, b, c, d);
        return 0;
    

}