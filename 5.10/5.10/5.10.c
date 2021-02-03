#include <stdio.h>
#include <stdlib.h>
int main()
{
	char tab[1001];
	printf("Podaj tekst:\n");
	if (fgets(tab, 1001, stdin) == NULL) {
		printf("Incorrect input");
		return 1;
	}
	//printf("%s", tab);
	int count = 0, countOfWords = 0;
	int maxCount = 0;
	
	for (int i = 0; i < 10000; i++) {
		if (tab[i] == '\n') {
			break;
		}
		if ((65<=tab[i] && 90>=tab[i]) || (97 <= tab[i] && 122 >= tab[i])) {
			count++;
		}
		else if(tab[i] == ' ') {
			
			if (count > maxCount) {
				maxCount = count;
				
			}
			//count = 0;
		}
		else {
			printf("Incorrect input");
			return 1;
		}
		countOfWords++;
	}
	count = 0;
	int numFoLongWords = 0;
	for (int i = countOfWords-1; i >= 0; i--) {
		if (tab[i] != ' ') {
			count++;

		}
		if (tab[i] == ' ' || i == 0) {
			if (i == 0) {
				i--;
			}
			if (count == maxCount) {
				numFoLongWords++;

			}
			count = 0;
		}
	}
	printf("%d %d\n", numFoLongWords, maxCount);
	for (int i = countOfWords - 1; i >= 0; i--) {
		if (tab[i] != ' ') {
			count++;
			
		}
		if(tab[i] == ' '|| i == 0) {
			if (i == 0) {
				i--;
			}
			if (count == maxCount) {
				for (int j = i + 1; j < i + maxCount + 1; j++) {
					printf("%c", tab[j]);
				}
				printf("\n");
				
			}
			count = 0;
		}
	}
	return 0;
}
