#include <stdio.h>

int *getArray();

int main() {
    int *array = getArray();
    printf("array 0: %d\n", array[0]);
    printf("array 1: %d\n", array[1]);
    printf("array 2: %d\n", array[2]);
    return 0;
}

int *getArray() {
    int array[] = {1, 2, 3};
    int *loc = calloc(array);
    return &array[0];
}
