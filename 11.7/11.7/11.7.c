

#include <stdio.h>

char* reverse(char* text, int isSingleWordReverse) {
	if (text == NULL) {
		return NULL;
	}
	int i = 0;

	while ((isSingleWordReverse == 0 && *(text + i) != '\0') ||
			(isSingleWordReverse == 1 && (*(text + i) != ' ') && *(text + i) != '\0') ) {
		i++;
	}
	int n = i;
	for (int j = 0; j < (i / 2); j++) {
		char temp;
		temp = *(text + j);
		*(text + j) = *(text + n - 1);
		*(text + n - 1) = temp;
		n--;
	}
	return text;
}
char* remove_non_letters(char* text) {
	if (text == NULL) {
		return NULL;
	}
	int i = 0;
	while (*(text + i) != '\0') {
		char tempT = *(text + i);
		if (!(tempT <= 'z' && tempT >= 'a' || tempT <= 'Z' && tempT >= 'A')) {
			*(text + i) = ' ';
		}
		i++;
	}
	return text;
}
char* trim(char* text) {
	if (text == NULL) {
		return NULL;
	}
	int i = 0;
	int spaceCounter = 0;
	int firstSpace = 1;
	while (*(text + i) != '\0') {
		char tempT = *(text + i);
		if (i == 0 && tempT != ' ') {
			firstSpace = 0;
		}
		if (tempT == ' ') {
			spaceCounter++;
		}
		if (tempT != ' ' && ((spaceCounter > 1) || (spaceCounter == 1 && firstSpace == 1))) {
			int n = i;
			while (*(text + n) != '\0') {
				if (firstSpace == 1) {
					*(text + n - spaceCounter) = *(text + n);
				}
				else {
					*(text + n - spaceCounter + 1) = *(text + n);
				}
				n++;
			}
			if (firstSpace == 1) {
				*(text + n - spaceCounter) = '\0';
			}
			else
			{
				*(text + n - spaceCounter + 1) = '\0';
			}

			i = i - spaceCounter;
			spaceCounter = 0;
			firstSpace = 0;
		}
		if (tempT != ' ' && spaceCounter == 1) {
			spaceCounter = 0;
		}
		i++;
	}
	if (spaceCounter != 0) {
		*(text + i - spaceCounter) = '\0';
	}
	return text;
}
char* swap_order_words(char* txt) {
	if (txt == NULL) {
		return NULL;
	}
	remove_non_letters(txt);
	trim(txt);

	

	reverse(txt, 0);
	int i = 0;
	int firstSign = 0;
	while (*(txt + i) != '\0') {
		char tempT = *(txt + i);

		if (tempT != ' ' && firstSign == 0) {
			reverse(txt + i, 1);
			firstSign = 1;
		}
		if (tempT == ' ') {
			firstSign = 0;
		}
		i++;
	}
	return txt;
}
int main()
{
	char tab[1001];
	//char tab2[] =  "\n" ;
	//I am enough of an artist to draw freely upon my imagination. Imagination is more important than knowledge. Knowledge is limited. Imagination encircles the world. - Albert Einstein
	//could else to same contest intelligence \t hands interfaces, in   Eliezer down Anything Intelligence, to the the \t give enhancement of that beyond the rise world. change even intelligence neuroscience-based Artificial in \t league. doing Nothing as Yudkowsky - or smarter-than-human human - the \n form brain-computer - most is wins
	//char tab2[] = " +alking and begin doing    Walt Disney";

	printf("Wpisz zadnie: \n");
	if (scanf("%1000[^\n]", tab) != 1) {
		printf("incorrect input");
		return 1;
	}

	swap_order_words(tab);
	

	if (*(tab + 0) == '\0') {
		printf("show to Nothing");
	}
	else {
		printf("%s", tab);
	}
	return 0;
}
