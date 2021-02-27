#include <stdio.h>
#include <stdlib.h>

enum type_t {
    INTEGER,
    DOUBLE,
    CHARACTER
};

struct data_t
{
    enum type_t type;
    union {
        int i;
        double d;
        char c;
    };
};

double convert_to_double(struct data_t* element) {
    double temp = 0.0;
    switch (element->type)
    {
    case INTEGER: {
        temp = (double)element->i;
        break;
    }
    case DOUBLE: {
        temp = element->d;
        break;
    }
    case CHARACTER: {
        temp = (double)element->c;
        break;
    }
    default:
        break;
    }
    return temp;
}

int sort(struct data_t* data[], int size) {

    if (data == NULL || size <= 0) {
        return 1;
    }
    struct data_t *temp; // zmienna zo zamiany miejsc w przypadku sortowania
    int ifchange = 0;
    for (int i = 0; i < size - 1; i++) {
        ifchange = 0;
        for (int j = 1; j < size - i; j++) { //p?tla do por?wnainia czy nie ma zmiennej wi?kszej od pierwszej
            struct data_t* element = *(data + j -1);
            struct data_t* elementNext = *(data + j);
            double elementT = convert_to_double(element);
            double elementNextT = convert_to_double(elementNext);
           
            if (elementT < elementNextT) {// czy poprzedni element wi?kszy od poprzedniego
                //zamiana miejscami
                ifchange = 1;
                temp = *(data + j); // zapisjue sobie tab od j ?eby nie straci? zmiennej
                *(data + j) = *(data + j - 1); // podmieniam zmienn?
                *(data + j - 1) = temp;// powracam do warto?ci wcze?niejszej
            }
            else if (elementT == elementNextT && element->type != elementNext->type) {// zank ,zm, int
                //w 119
                if (element->type == DOUBLE && elementNext->type == CHARACTER || 
                    element->type == INTEGER && (elementNext->type == DOUBLE || elementNext->type == CHARACTER)) {
                    ifchange = 1;
                    temp = *(data + j); // zapisjue sobie tab od j ?eby nie straci? zmiennej
                    *(data + j) = *(data + j - 1); // podmieniam zmienn?
                    *(data + j - 1) = temp;// powracam do warto?ci wcze?niejszej
                }
                
            }
            
        }
        if (ifchange == 0) {
            break;
        }
        
        

    }

    return 0;
}

void display(struct data_t* data[], int size) {
    if (data == NULL || size <= 0) {
        return;
    }
    int i = 0;
   while (i < size) {
       struct data_t* element = *(data + i);
        switch (element->type)
        {
        case INTEGER: {
            printf("%d ", element->i);
            break;
        }
        case DOUBLE: {
            printf("%f ", element->d);
            break;
        }
        case CHARACTER: {
            printf("%c ", element->c);
            break;
        }
        default:
            break;
        }
        i++;
    }
}

int clasifyText(const char* text) {
    int i = 0;
    int clasification = 0;
    if (*(text) >= '!' && *(text) <= '/' || *(text) >= ':' && *(text) <= '~') {
        if (*(text + 1) == '\0') {
            //clasification = 2;
            return 2;
        }
        else if(!(*(text+1) >= '0' && *(text+1)<='9')) {
            return -1;
        }
    }
    while (*(text + i) != '\0') {
        char element = *(text + i);
        if (element < '0') {
            if (element == '.' || element == '-') {
                if(element == '.'){
                    if (i > 0) {
                        clasification = 1;
                    }
                    else {
                        return -1;
                    }
                }
                if (element == '-' && i > 0) {
                    return -1;
                }

            }
            else {
                return -1;
            }
        }
        if (element > '9') {
            return -1;
        }
        i++;
    }
    if (i > 0) {
        if (!(*(text + i - 1) >= '0' && *(text + i - 1) <= '9')) {
            return -1;
        }
    }
    //clasification = 0;
    return clasification;
}
int read_text(char* text) {
    int i = 0;
    while (1) {
        char temp = getchar();
        if (temp == '\n') {
            *(text + i) = '\0';
            return 1;
        }
        if (temp == ' ') {
            *(text + i) = '\0';
            break;
        }
        *(text + i) = temp;
        i++;
    }
    return 0;
}
/*void test() {
    //struct data_t input[] = { {.i = -81, .type = INTEGER }, {.c = 'h', .type = CHARACTER }, {.d = -23.88714380356454, .type = DOUBLE }, {.d = -47.77728341263197, .type = DOUBLE }, {.i = -91, .type = INTEGER }, {.i = -88, .type = INTEGER }, {.i = -15, .type = INTEGER }, {.i = -3, .type = INTEGER }, {.c = 'B', .type = CHARACTER }, {.i = 66, .type = INTEGER }, {.c = 'M', .type = CHARACTER }, {.i = 119, .type = INTEGER }, {.c = 'X', .type = CHARACTER }, {.d = -9.256794498397355, .type = DOUBLE }, {.c = 'w', .type = CHARACTER }, {.i = 119, .type = INTEGER }, {.c = 'w', .type = CHARACTER }, {.d = -92.28430976499418, .type = DOUBLE }, {.i = 77, .type = INTEGER }, {.i = 88, .type = INTEGER }, {.i = 104, .type = INTEGER }, };
    //struct data_t input[] = { {.i = 119, .type = INTEGER }, {.c = 'w', .type = CHARACTER }, {.d = -92.28430976499418, .type = DOUBLE }, {.i = 77, .type = INTEGER }, {.i = 88, .type = INTEGER }, {.i = 104, .type = INTEGER }, };

    struct data_t* ptr_data[21];
    for (int j = 0; j < 21; ++j)
        ptr_data[j] = input + j;
    sort(ptr_data, 21);
    display(ptr_data, 21);
}*/
int main()
{
     struct data_t *tab[100];
     int i = 0;
     printf("Enter elements (single characters, signed integers and doubles):");
     while (1) {
         
        char temp[30];
        int retValue = read_text(temp);
        
        if (i == 100) {
            break;
        }
        int result = clasifyText(temp);
        struct data_t* element = malloc(sizeof(struct data_t));
        
        switch (result)
        {
        case INTEGER: {
            int tempInt = atoi(temp);
            element->i = tempInt;
            element->type = INTEGER;
            break;
        }
        case DOUBLE: {
            double tempDouble = atof(temp);
            element->d = tempDouble;
            element->type = DOUBLE;
            break;
        }
        case CHARACTER: {
            char tempChar = *(temp);
            element->c = tempChar;
            element->type = CHARACTER;
            break;
        }

        default:
            printf("Incorrect input data");
            for (int j = 0; j < i; j++) {
                free(*(tab + j));
            }
            free(element);
            return 2;
        }
        *(tab + i) = element;
        i++;
        if (retValue == 1) {
            break;
        }
    }
     //display(tab, i);
     sort(tab, i);
     //printf("\n");
     display(tab, i);
     for (int j = 0; j < i; j++) {
         free(*(tab + j));
     }
    //test();
	return 0;
}
