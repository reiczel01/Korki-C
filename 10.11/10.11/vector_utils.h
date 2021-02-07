
int read_vector(int* tab, int size, int stop_value);
void display_vector(const int* tab, int size);
int shift(int* array, int array_size, int positions_to_shift, enum direction dir);
enum direction {
    ROTATE_LEFT = 1,
    ROTATE_RIGHT
};