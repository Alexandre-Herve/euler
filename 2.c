#include <stdio.h>

int main() {
    long limit = 4000000;
    long sum = 0;
    long a = 1;
    long b = 2;
    long c;

    while(b < limit) {

        if( b % 2 == 0) {
            sum += b;
        }

        c = a + b;
        a = b;
        b = c;
    }

    printf("%ld\n", sum);
    return 0;
}
