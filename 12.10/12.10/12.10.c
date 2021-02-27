

#include <stdio.h>

char* space_changer(char* text) {
	if (text == NULL ) {
		return 1;
	}
    int i = 0;
    while (*(text + i) != '\0') {

        if (*(text + i) == ' ') {
            *(text + i) == '_';
        return 0;
        }
        i++;
    }
}

int main()
{
	
	return 0;
}
