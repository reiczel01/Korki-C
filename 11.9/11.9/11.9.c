


#include <stdio.h>

int connect(const char* t1, const char* t2, const char* t3, char* t4, int size) {
	if (t1 == NULL || t2 == NULL || t3 == NULL || t4 == NULL || size < 0) {
		return 1;
	}
	int j = 0;
	int i = 0;
	while (*(t1 + j) != '\0') {
		*(t4 + i) = *(t1 + j);
		i++;
		j++;
		if (i >= size) {
			return 1;
		}
	}
	*(t4 + i) = ' ';
	i++;
	j = 0;
	while (*(t2 + j) != '\0') {
		*(t4 + i) = *(t2 + j);
		i++;
		j++;
		if (i >= size) {
			return 1;
		}
	}
	*(t4 + i) = ' ';
	i++;
	j = 0;
	while (*(t3 + j) != '\0') {
		*(t4 + i) = *(t3 + j);
		i++;
		j++;
		if (i >= size) {
			return 1;
		}
	}
	*(t4 + i) = '\0';
	return 0;
}
void
clear(void)
{
	while (getchar() != '\n');
}
int main()
{
	char tab1[1001], tab2[1001], tab3[1001], tab4[3003];
	printf("Podaj tekst: \n");
	if (scanf("%1000[^\n]", tab1) != 1) {
		printf("incorrect input");
		return 1;
	}
	clear();
	printf("Podaj tekst: \n");
	if (scanf("%1000[^\n]", tab2) != 1) {
		printf("incorrect input");
		return 1;
	}
	clear();
	printf("Podaj tekst: \n");
	if (scanf("%1000[^\n]", tab3) != 1) {
		printf("incorrect input");
		return 1;
	}
	connect(tab1, tab2, tab3, tab4, 3003);


	//if (*(tab + 0) == ' ') {
		//printf("show to Nothing");
	//}
	//else {
		printf("%s", tab4);
	//}
	return 0;
}