

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
struct point_t {
	int x;
	int y;
};
void show(const struct point_t* p) {
	if (p != NULL) {
		printf("x = %d; y = %d\n", p->x, p->y);
	}
}
struct point_t* read(struct point_t* p) {
	if (p == NULL) {
		return NULL;
	}
	printf("Podaj współrzędną x: ");
	if (scanf("%d", &p->x) != 1) {
		
		return NULL;
	}
	printf("Podaj współrzędną y: ");
	if (scanf("%d", &p->y) != 1) {
		
		return NULL;
	}
	return p;
}
struct point_t* set(struct point_t* p, int x, int y) {
	if (p == NULL) {
		return NULL;
	}
	p->x = x;
	p->y = y;
	return p;
}
float distance(const struct point_t* p1, const struct point_t* p2, int* err_code)
{
	if (p1 == NULL || p2 == NULL) {
		if (err_code != NULL) {
			*err_code = 1;
		}
		return -1;
	}
	float x = p1->x - p2->x; 
	float y = p1->y - p2->y;
	float dist;

	dist = pow(x, 2.0) + pow(y, 2.0);       
	dist = sqrt(dist);
	if (err_code != NULL) {
		*err_code = 0;
	}
	return dist;
	
}

int main()
{
	struct point_t p1, p2;
	
	//struct point_t* p_wsk = &p1; 
	if (read(&p1) == NULL) {
		printf("Incorrect input");
		return 1;
	}
	srand(time(NULL));
	
	set(&p2, (rand() % 20 - 10), (rand() % 20 - 10));
	
	show(&p1);
	show(&p2);

	//printf("%d", p_wsk->y);
	float returnFn = distance(&p1, &p2, NULL);
	printf("%.2f", returnFn);
	return 0;
}
