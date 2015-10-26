#include <stdio.h>

int main()
{
    long number = 600851475143;
    long max_factor = 1;
    int i;

    while(number > 1) {
        i = 1;
        while(i < number) {
            i++;
            if(number % i == 0) {
                number = number / i;
                max_factor = i;
                break;
            }
        }
    }

    printf("max factor: %ld\n", max_factor);
}
