#include <stdio.h>

int findDividers[] (int num);

int main() {
    int dividersCount[20];
    int dividers[20];
    int ppcm = 1;
    int i;

    for(i=1; i<20; i++) {
        dividersCount[i] = 0;
    }

   for(i=0; i<20; i++) {
        dividers = findDividers(i);
        for (i=2; i<20; i++) {
            printf("dividersCount[i]: %d\n", dividersCount[i]);
            if(*dividersCount[i] < dividers) {
                *dividersCount[i] = dividers;
            }
            dividers++;
        }
    }

    /*
     * for(i=0; i<20; i++) {
     *     ppcm *= dividersCount[i];
     * }
     */

    printf("PPCM: %d\n", ppcm);
    return 0;
}

int findDividers[] (int num) {
    int i;
    int dividers[20];

    for(i=0; i<20; i++) {
        dividers[i] = 0;
    }

    do {
        for(i=2; i<20; i++) {
            if(num % i == 0) {
                dividers[i] += 1;
                num /= i;
            }
        }
    } while (num > 1);

    return dividers;
}
