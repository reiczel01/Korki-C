#ifndef INC_10_11_VECTOR_UTILS_H//zabespiecza przed inkludowaniem plików kilkakrotnie
#define INC_10_11_VECTOR_UTILS_H
enum direction {
    ROTATE_LEFT = 2,
    ROTATE_RIGHT = 1
};
int read_vector(int* tab, int size, int stop_value);
void display_vector(const int* tab, int size);
int shift(int* array, int array_size, int positions_to_shift, enum direction dir);
#endif //INC_10_11_VECTOR_UTILS_H