

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
struct point_t {
	int x;
	int y;
};
struct segment_t {
	struct point_t start;
	struct point_t end;
};
void show(const struct point_t* p) {
	if (p != NULL) {
		printf("x = %d; y = %d\n", p->x, p->y);
	}
}
void show_segment(const struct segment_t* p) {
	if (p != NULL) {
		printf("Line start coords: ");
		show(&p->start);
		printf("Line end coords: ");
		show(&p->end);
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
struct segment_t* read_segment(struct segment_t* p) {
	if (p == NULL) {
		return NULL;
	}
	printf("Enter coordinates of the first point:\n");
	if (read(&p->start) == NULL) {
		return NULL;
	}
	printf("Enter coordinates of the second point:\n");
	if (read(&p->end) == NULL) {
		return NULL;
	}
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
float length(const struct segment_t* s, int* err_code) {
	if (s == NULL) {
		if (err_code != NULL) {
			*err_code = 1;
		}
		return -1;
	}
	return distance(&s->start, &s->end, err_code);
	
}

int main()
{
	
	struct segment_t s;
	//struct point_t* p_wsk = &p1; 
	if (read_segment(&s) == NULL) {
		printf("Incorrect input");
		return 1;
	}




	show_segment(&s);
	

	//printf("%d", p_wsk->y);
	float returnFn = length(&s, NULL);
	printf("%.2f", returnFn);
	return 0;
}
