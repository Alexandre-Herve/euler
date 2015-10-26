#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int size;
} tTuple;

int isPal(int num);
tTuple numToArray(int num);

int main() {
    long max_pal = 0;
    int min_mult = 100;
    int max_mult = 999;

    long product;
    int i;
    int j;

    for (i = max_mult; i > min_mult - 1; i--) {
        for (j = i; j > min_mult - 1; j--) {
            product = i * j;
            if(isPal(product) == 1 && product > max_pal) {
                max_pal = product;
            }
        }
    }

    printf("Found %ld\n", max_pal);
    return 0;
}

int isPal (int num) {
    tTuple tuple = numToArray(num);
    int *arrNum = tuple.array;

    int size = tuple.size;
    int iterations = size;

    if(iterations % 2 == 1) {
        iterations -=1;
    }

    iterations = iterations / 2;

    printf("iterations: %d\n", iterations);

    while(iterations > 0) {
        if(arrNum[size - iterations] != arrNum[iterations - 1]) {
            return 0;
        }
        iterations -= 1;
    }
    return 1;
}

tTuple numToArray(int num) {
    unsigned int length = (int)(log10((float)num)) + 1;
    int array[length];

    printf("num: %d\n", num);
    for(int i = length - 1; i>=0; i--) {
        array[i] = num % 10;
        num /= 10;
    }

    tTuple tuple;
    tuple.array = array;
    tuple.size = length;

    return tuple;
}
