


#include <stdio.h>
#include <string.h>
int marks_counter(const char* text, int* uppercase, int* lowercase, int* whitespace) {
	if (text == NULL || uppercase == NULL || lowercase == NULL || whitespace == NULL) {
		return 1;
	}
	(*uppercase) = 0;
	(*lowercase) = 0;
	(*whitespace) = 0;
	if (strlen(text) == 0) {
		return 0;
	}
	int i = 0;
	while (*(text + i) != '\0') {
		char tekstZN = *(text + i);
		if (tekstZN == ' ' || tekstZN == '\t' || tekstZN == '\n') {
			(*whitespace)++;
		}
		else if(tekstZN >= 'a' && tekstZN <= 'z'){
			(*lowercase)++;
		}
		else if(tekstZN >= 'A' && tekstZN <= 'Z'){
			(*uppercase)++;
		}
		
		i++;
	}
	
	
	return 0;
}
int main()
{
	char tab[1001];
	int uppercase = 0, lowercase = 0, whitespace = 0;
	printf("Podaj tekst: ");
	fgets(tab, 1000, stdin);
	for (int i = 0; i < 1000; i++) {
		if (*(tab + i) == '\n') {
			*(tab + i) = '\0';
			break;
		}
	}
	marks_counter(tab, &uppercase, &lowercase, &whitespace);
	printf("%d\n", uppercase);
	printf("%d\n", lowercase);
	printf("%d", whitespace);
	/*marks_counter("is \n it \t \"To do see \t and not   courage.\"- is of what   right Confucious lack a \n", &uppercase, &lowercase, &whitespace);
	printf("%d\n", uppercase);
	printf("%d\n", lowercase);
	printf("%d", whitespace);*/
	return 0;
}
