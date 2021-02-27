#ifndef INC_SORT_H
#define INC_SORT_H

enum direction{
	ASCENDING  = 1,
	DESCENDING
};
int selection_sort_asc(int tab[], int size);
int selection_sort_desc(int tab[], int size);
int selection_sort(int tab[], int size, enum direction dir);
#endif //INC_SORT_H