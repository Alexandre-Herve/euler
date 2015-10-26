#include <stdio.h>
#include <math.h>

int *findDividers (int num);

int main() {
  int dividersCount[20];
  int *dividers;
  int factor;
  long ppcm = 1;
  int i, j;

  for(i=1; i<20; i++) {
    dividersCount[i] = 0;
  }

  for(i=2; i<20; i++) {
    dividers = findDividers(i);
    for (j=2; j<20; j++) {
      if(*(dividersCount + j) < *(dividers + j)) {
        *(dividersCount + j) = *(dividers + j);
      }
    }
  }

  for(i=1; i<20; i++) {
    factor = pow(i, *(dividersCount + i));
    ppcm *= factor;
  }

  printf("PPCM: %ld\n", ppcm);
  return 0;
}

int *findDividers (int num) {
  int i;
  static int dividers[20];

  for(i=0; i<20; i++) {
    dividers[i] = 0;
  }

  for(i=2; i<20; i++) {
    while (num % i == 0) {
      dividers[i] += 1;
      num /= i;
    }
  }

  return dividers;
}
